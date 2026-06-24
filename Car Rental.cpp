#include<iostream>
#include<string>
#include<fstream>
#include <io.h>
#include <fcntl.h>
#include<Windows.h>
using namespace std;

//Structures

struct car_detail {

	string model;
	string type;
	int year = 0;
	float price_per_day = 0;
	bool is_available = false;

};
struct customer_detail {
	long long customer_id = 0;
	long long license_number = 0, contact_info = 0;
	string name;
};
struct booking_detail {
	int customer_id = 0;
	int days = 0;

};
struct payment_detail {
	float total_cost = 0;
	float amount_paid = 0;
	string payment_method;
};


car_detail cars[13];
customer_detail customer[13];
booking_detail booking[13];
payment_detail payment[13];

int car_count = 0;
int customer_count = 0;
int booking_count = 0;
int payment_count = 13;


void loadUsersFromFile()
{
	ifstream fin("users.txt");
	if (!fin)
		return;

	string name;
		long long customer_id, license_number, contact_info;
	while (customer_count < 13 && getline(fin, name))
	{


		if (!(fin >> customer_id >> license_number >> contact_info))
			break;
			customer[customer_count].name = name;
			customer[customer_count].customer_id = customer_id;
			customer[customer_count].license_number = license_number;
			customer[customer_count].contact_info = contact_info;
			customer_count++;
			
		
	}
	fin.close();
}
void menu();
void initialize_cars();
void show_all_cars();
void add_car();
void add_customer();
void booking_data();
void customer_profile();
void payment_process();




void menu()
{
	

	cout << "╔═════════════════════╗" << endl;
	cout << "║ WELCOME TO CAR RENTAL ║" << endl;
	cout << "╚═════════════════════╝" << endl;

	cout <<
		"---- 1. Add Car ------------------\n" <<
		"---- 2. Register Customer --------\n" <<
		"---- 3. View Available Cars ------\n" <<
		"---- 4. Book a Car ---------------\n" <<
		"---- 5. View Customer Profile ----\n" <<
		"---- 6. Make Payment -------------\n" <<
		"---- 7. Generate Invoice ---------\n" <<
		"---- 8. Exit ----\n\n";
}

void initialize_cars()
{
	car_detail initial_cars[10] = {

					{"Lamborghini Huracan",    "EXOTIC", 2024, 2200, true},

					{"Ferrari 488 GTB",        "EXOTIC", 2023, 1800, true},

					{"Rolls-Royce Ghost",      "LUXURY", 2024, 1500, true},

					{"Bentley Continental GT", "LUXURY", 2024, 1200, true},

					{"Porsche 911 Carrera",    "SPORTS",  2024, 800, true},

					{"Nissan GT-R",            "SPORTS",  2023, 900, true},

					{"Porsche Cayenne Turbo",  "SUV",     2024, 600, true},

					{"Bentley Bentayga",       "SUV",    2024, 1400, true},

					{"Genesis G90",            "SEDAN",   2024, 300, true},

					{"Cadillac CT5-V",         "SEDAN",   2024, 250, true}

	};
	for (int i = 0; i < 10; i++)
	{
		cars[i] = initial_cars[i];
	}
	car_count = 10;
}

void show_all_cars()
{
	cout << "\n\t\t\t-------- List of ALL Cars --------\n\n";
	for (int i = 0; i < car_count; i++)
	{
		cout << i + 1 << ".  |" << cars[i].model << "| (" << cars[i].type << ", "
			<< cars[i].year << ")" << " - $" << cars[i].price_per_day << " /Day"
			<< " - " << (cars[i].is_available ? "Available" : "Booked") << endl << endl;
	}
	cout << "                        ----------------------------------\n";
}

void add_car()

{

	if (car_count > 12)
	{
		cout << "Cannot add more cars! Garage is full." << endl;
		return;
	}
	cin.ignore();
	cout << "Enter Car Model: ";
	getline(cin, cars[car_count].model);

	cout << "Enter Car Type: ";
	getline(cin, cars[car_count].type);

	cout << "Enter Year: ";
	cin >> cars[car_count].year;

	cout << "Enter Price Per Day: ";
	cin >> cars[car_count].price_per_day;

	cout << "Is Available? (1 for yes, 0 for no): ";
	cin >> cars[car_count].is_available;

	car_count++;
	cout << "\nCar added successfully!\n";
	system("pause");
	system("cls");



}

void add_customer()
{
	if (customer_count >= 13)
	{
		cout << "Cannot add more customers! Database is Full." << endl;
		return;
	}

	cin.ignore();
	cout << "Your Name: ";
	getline(cin, customer[customer_count].name);
	cout << "Your ID: ";
	cin >> customer[customer_count].customer_id;

	cout << "License Number: ";
	cin >> customer[customer_count].license_number;

	cout << "Contact Number: ";
	cin >> customer[customer_count].contact_info;

	cout << "Customer added successfully!" << endl<<endl;
	ofstream fout("users.txt", ios::app);
	if (fout)
	{
		fout << customer[customer_count].name << "\n" << customer[customer_count].customer_id
			<< "\n" << customer[customer_count].license_number << "\n" << customer[customer_count].contact_info << endl;

	}
	fout.close();
	customer_count++;
	system("pause");
	system("cls");
}
int car_choice;
void booking_data()
{

	if (car_count == 0)
	{
		cout << "No cars available for booking" << endl;
		return;
	}
	if (booking_count > 12)
	{
		cout << "Sorry Sir, All Cars are Booked.";
		return;
	}
	show_all_cars();
	cout << "Enter a Car number to Book: ";
	cin >> car_choice;

	while (car_choice <= 0 || car_choice > car_count)
	{
		cout << "Invalid Car Selection! Try Again." << endl;
		cout << "Enter a Car number to Book: ";
		cin >> car_choice;
	}
	while (!cars[car_choice - 1].is_available || car_choice <= 0 || car_choice > car_count)
	{
		if (car_choice <= 0 || car_choice > car_count)
		{
			while (car_choice <= 0 || car_choice > car_count)
			{
				cout << "Invalid Car Selection! Try Again." << endl;
				cout << "Enter a Car number to Book: ";
				cin >> car_choice;
			}
		}
		else

		{
			cout << "This Car is Booked. Please! Choose Different One." << endl;
			cout << "Enter a Car number to Book: ";
			cin >> car_choice;
		}
	}

	while (true) {

		cout << "Enter Your Customer ID: ";
		cin >> booking[customer_count - 1].customer_id;
		while (customer[customer_count-1].customer_id != booking[customer_count-1].customer_id)
		{
			cout << "ID Didn't Match. Please Try Again." << endl << endl;
			cout << "Enter Your Customer ID: ";
			cin >> booking[customer_count-1].customer_id;
		}

		if (!cin.fail() && booking[customer_count].customer_id >= 0 && booking[customer_count].customer_id <= 999999999999999)
		{
			break;
		}
		cout << "Invalid ID! Try Again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}


	while (true) {
		cout << "Enter Days: ";
		cin >> booking[customer_count].days;

		if (!cin.fail()) {
			break;
		}
		cout << "Invalid input! Enter a number." << endl;
		cin.clear();
		cin.ignore(1000, '\n');


	}
	cout << "You Booked a Car, Now Proceed to Payment" << endl;
	system("pause");
	system("cls");


}
int flag3 = 0;
void customer_profile()
{
	;
	if (flag3 == 0)
	{
		cout << "\nThere Is No Customer Profile Yet In The Database." << endl<<endl;
	}
	else
	{
		for (int i = 0; i < customer_count && i < 13; i++)
		{
			cout << endl << "Name: " << customer[i].name << endl << "ID: " << customer[i].customer_id << endl
				<< "Contact Number: " << customer[i].contact_info << endl << "License Number: " << customer[i].license_number << endl << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

void payment_process()
{
	int x = 1;
	cout << "Cash or Card: ";

	for (int i = car_choice - 1;x < payment_count; x++)
	{
		cin >> payment[i].payment_method;
		payment[i].total_cost = cars[i].price_per_day * booking[customer_count].days;
		cout << "\nTotal Cost For " << booking[customer_count].days << " Days = $" << payment[i].total_cost << endl;
		break;
	}
	cout << "\nNow You Can Generate Invoice." << endl;
	if (customer[customer_count + 1].customer_id == NULL)
	{
	}
	else
	{
	}
	system("pause");
	system("cls");
}


int main()
{
	loadUsersFromFile();
	initialize_cars();

	int flag = 0;
	int flag2 = 0;

	 
	int choice, t, i=0;
	do
	{
	    menu();
		cout << "\nEnter Your Choice (1 to 8): ";
		cin >> choice;
		switch (choice)
		{


		case 1:
			add_car();
			break;
		case 2:
			flag = -1;
			flag3 = -1;
			add_customer();
			cout << "\nBook Now. Drive Soon." << endl;
			break;
		case 3:
			show_all_cars();
			break;
		case 4:
			if (flag == 0)
			{
				cout << "\nPlease! Register Yourself From (Add Customer)..." << endl << endl;
				cout << "There Is No Customer Profile Yet In The Database." << endl<<endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{

				booking_data();
				flag2 = -1;
				break;
			}
		case 5:
			customer_profile();
			break;
		case 6:
		
			if (flag == 0 || flag2 == 0)
			{
				cout << "\nPlease Book a Car First..." << endl<<endl;
				system("pause");
				system("cls");
				break;

			}
			else
			{
				payment_process();
				cars[car_choice - 1].is_available = false;
				break;

			}
		case 7:

			t = car_choice - 1;
			if (flag == -1)
			{
				if (booking[i].customer_id != customer[i].customer_id)
				{
					i++;
				}
				else{ }
				cout << "Car Booked: " << cars[t].model << " (" << cars[t].type << ", " << cars[t].year << " )" << endl << endl << "Customer Name: " << customer[i].name << endl << endl
					<< "Customer ID: " << customer[i].customer_id << endl << endl << "License Number: " << customer[i].license_number << endl << endl << "Contact Number: " << customer[i].contact_info <<
					endl << endl << "Daily Rent for " << cars[t].model << ": $" << cars[t].price_per_day << endl << endl << "Total Amount To Be Paid: $" << payment[t].total_cost << endl << endl
					<< "Amount Paid: $" << payment[t].total_cost << endl << endl << "Payment Method: " << payment[t].payment_method << endl<<endl;
				system("pause");
				system("cls");
				cars[car_choice - 1].is_available = false;
				i++;
				break;
			}

			else
			{
				cout << "\nPlease Book a Car First..." << endl<<endl;
				system("pause");
			    system("cls");
				break;
			}
			
		case 8:
			return 0;
		default:
			cout << "\nInvalid Choice, Try Again." << endl<<endl;
			system("pause");
			system("cls");

		}


	} while (choice != 8);
	return 0;





}