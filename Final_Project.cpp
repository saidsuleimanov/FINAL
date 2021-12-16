#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

class AdminPanel {
public:
	int budce = 0;
	int mushroom_say = 100;
	int meat_say = 100;
	int cheese_say = 100;
	int tomatoes_say = 100;
	int& GetMushroom() { return mushroom_say; }
	int& GetMeat() { return meat_say; }
	int& GetCheese() { return cheese_say; }
	int& GetTomatoes() { return tomatoes_say; }
	int& GetBudce() { return budce; }
	AdminPanel() = default;

	bool Login(string login, int password) {
		if (login == "admin" && password == 1) {
			return true;
		}
	};

	void check_all() {
		ifstream file("ingrediyent.txt");
		if (file.is_open()) {
			string value;
			string total = "";

			while (!file.eof()) {
				getline(file, value);
				total += value + "\n";
			}
			cout << total;
		}

		file.close();
	}
	void user() {
		ifstream file("user.txt");

		if (file.is_open()) {
			string value;
			string total = "";

			while (!file.eof()) {
				getline(file, value);
				total += value + "\n";
			}
			cout << total;
		}

		file.close();

	}

	void Budce_bax() {
		ifstream file("budce.txt");

		if (file.is_open()) {
			file.clear();
			string value;
			string total = "";

			while (!file.eof()) {
				getline(file, value);
				total += value + " AZN\n";
			}
			cout << "Restoranin Budcesi: " << total << endl;
		}

		file.close();
	}


};
class UserPanel {
public:
	string login;
	int pass;
	string login2;
	int pass2;
	UserPanel() = default;
	bool SignUp() {
		string reguser, regpass, ru, rp;
		system("cls");
		cout << "Usernameni daxil edin :";
		cin >> reguser;
		cout << "\nPasswordu daxil edin :";
		cin >> regpass;

		ofstream reg("user.txt", ios::app);
		reg << reguser << ' ' << regpass << endl;
		system("cls");
		cout << "\nQeydiyyat Ugurludur\n";
		return 1;

	}
	bool SignIn() {
		int count = 0;;
		string user, pass, u, p;
		system("cls");
		cout << "Melumatlari daxil edin: " << endl;
		cout << "USERNAME :";
		cin >> user;
		cout << "PASSWORD :";
		cin >> pass;

		ifstream input("user.txt");
		while (input >> u >> p)
		{
			if (u == user && p == pass)

			{
				count = 1;
				system("cls");

			}
			if (u != user && p != pass)

			{
				count = 0;
				system("cls");
				cout << "Bele istifadeci tapilmadi..." << endl;

			}

		}
		if (count == 1)
		{
			cout << "\Salam " << user << "\n Girish Ugurludur !" << endl;
			Sleep(900);
			system("cls");

			return 1;

		}
		else
		{
			count = 0;
			cout << "\nGirish ugursuzdur ! Login ve ya password sehvdir !" << endl;
			return 0;
		}
	}


};
class Ingredient {
protected:
	double _fats;
	double _proteins;
	double _carbohydrates;
	int _calories;
	string name;

public:
	Ingredient() {
		_fats = NULL;
		_proteins = NULL;
		_carbohydrates = NULL;
		_calories = NULL;
	}
	Ingredient(const string& name, const double& fats, const double& proteins, const double& carbohydrates, const int& calories) {
		this->name = name;
		SetFats(fats);
		SetProteins(proteins);
		SetCarbohydrates(carbohydrates);
		SetCalories(calories);
	}
	virtual ~Ingredient() = 0 {}

	double GetFats() { return _fats; }
	double GetProteins() { return _proteins; }
	double GetCarbohydrates() { return _carbohydrates; }
	int GetCalories() { return _calories; }

	void SetFats(const double& fats) {
		if (fats < NULL) return;
		_fats = fats;
	}
	void SetProteins(const double& proteins) {
		if (proteins < NULL) return;
		_proteins = proteins;
	}
	void SetCarbohydrates(const double& carbohydrates) {
		if (carbohydrates < NULL) return;
		_carbohydrates = carbohydrates;
	}
	void SetCalories(const int& calories) {
		if (calories < NULL) return;
		_calories = calories;
	}
};

class Mushrooms :public Ingredient {
public:
	int say = 100;
	Mushrooms(const string& name, const double& fats, const double& proteins, const double& carbohydrates, const int& calories) :Ingredient(name, fats, proteins, carbohydrates, calories) {}
};

class Meat :public Ingredient {
public:
	Meat(const string& name, const double& fats, const double& proteins, const double& carbohydrates, const int& calories) :Ingredient(name, fats, proteins, carbohydrates, calories) {}
};

class Cheese :public Ingredient {
public:
	Cheese(const string& name, const double& fats, const double& proteins, const double& carbohydrates, const int& calories) :Ingredient(name, fats, proteins, carbohydrates, calories) {}
};

class Tomatoes :public Ingredient {
public:
	Tomatoes(const string& name, const double& fats, const double& proteins, const double& carbohydrates, const int& calories) :Ingredient(name, fats, proteins, carbohydrates, calories) {}
};

struct RecipetItem {
	Ingredient* ingredient;
	int amount;
};



class Dish {
protected:
	vector<RecipetItem*> ingredients;

public:
	string name;

	Dish() {}
	Dish(const string& name) { this->name = name; }
	virtual ~Dish() = 0 {}

	void addIngredient(Ingredient* ingredient, const int& amount) {
		ingredients.push_back(new RecipetItem{ ingredient, amount });
	}

	virtual void taste() const {
		cout << "I do not know what is this ? " << endl;
	}
	void printRecipe() const {
		AdminPanel pnl2;
		system("cls");
		cout << name << " Sifaris etdiniz. ";
		cout << "\nBizi secdiyiniz uchun teshekkurler\n";
	}
};

class Pizza :public Dish {
public:
	Pizza(const string& name) : Dish(name) {}
	void taste() const override {
		system("cls");
		cout << "Pizza" << endl;
	}
};

class Kabab :public Dish {
public:
	Kabab(const string& name) : Dish(name) {}
	void taste() const override {
		system("cls");
		cout << "Kabab" << endl;
	}
};

class Dolma :public Dish {
public:
	Dolma(const string& name) : Dish(name) {}
	void taste() const override {
		system("cls");
		cout << "Dolma" << endl;
	}
};

class CookingDevice {
protected:
	bool isCooked = false;
	int second;

public:
	Dish* dish;

	void cook() {

	}

	virtual ~CookingDevice() = 0 { delete dish; }
};

class Oven :public CookingDevice {
public:
	Oven() {
		AdminPanel pnl;
		dish = new Pizza("Qarishiq Pizza");
		second = 20;
		ofstream file("budce.txt", ios::app);
		file.setf(ios::left);

		if (file.is_open()) {
			file << "Budce: " << pnl.GetBudce() + 12.5 << endl;
		}

	}
};

class Pot :public CookingDevice {
public:
	Pot() {
		AdminPanel pnl;
		dish = new Dolma("Qarishiq Dolma");
		second = 30;
		ofstream file("budce.txt", ios::app);
		file.setf(ios::left);

		if (file.is_open()) {
			file << "Budce: " << pnl.GetBudce() + 9 << endl;
		}
	}
};

class Brazier :public CookingDevice {
public:
	Brazier() {
		AdminPanel pnl;
		dish = new Kabab("Babat Kabab");
		second = 25;
		ofstream file("budce.txt", ios::app);
		file.setf(ios::left);

		if (file.is_open()) {
			file << "Budce: " << pnl.GetBudce() + 7 << endl;
		}
	}
};


void menu() {
	cout << "Menyudan sechim edin: " << endl;
	cout << "1 Pizza" << endl;
	cout << "2.Dolma" << endl;
	cout << "3.Kabab" << endl;
	cout << "4.Exit" << endl;
}

void ingredients() {
	cout << "Ingredient sechin 1-4 araligi: " << endl;
	cout << "1.Mushroom" << endl;
	cout << "2.Meat" << endl;
	cout << "3.Cheese" << endl;
	cout << "4.Tomatoes" << endl;

}

template<typename T>
void appendIngredients(T* ptr, AdminPanel& pn1) {
	char choice;
	int amount;
	int say;

	while (true) {
		system("cls");
		ingredients();
		amount = 1;

		choice = _getch();
		if (int(choice) > 52 && int(choice) < 59) {
			cout << "1-4 araligi!!! (5 SANIYE SONRA TEKRAR EDIN !)" << endl;
			Sleep(1000);
			cout << "4" << endl;
			Sleep(800);
			cout << "3" << endl;
			Sleep(600);
			cout << "2" << endl;
			Sleep(400);
			cout << "1" << endl;
			Sleep(200);
			ingredients();
		}
		if (int(choice) > 48 && int(choice) < 53) {
			int sechim = 0;
			cout << "\nEnter ingredient amount: ";
			cin >> amount;
			if (int(choice == 49))
			{
				pn1.GetMushroom() -= amount;
				ofstream file("ingrediyent.txt");
				file.setf(ios::left);

				if (file.is_open()) {
					file.clear();
					file << "Gobelek sayi: " << pn1.GetMushroom() << "\n";
					file << "Et sayi: " << pn1.GetMeat() << "\n";
					file << "Pendir sayi: " << pn1.GetCheese() << "\n";
					file << "Tomat sayi: " << pn1.GetTomatoes() << "\n" << endl;

				}
				file.close();
				Sleep(1000);
			}

			if (int(choice == 50))
			{

				pn1.GetMeat() -= amount;
				ofstream file("ingrediyent.txt");
				file.setf(ios::left);

				if (file.is_open()) {
					file.clear();
					file << "Gobelek sayi: " << pn1.GetMushroom() << "\n";
					file << "Et sayi: " << pn1.GetMeat() << "\n";
					file << "Pendir sayi: " << pn1.GetCheese() << "\n";
					file << "Tomat sayi: " << pn1.GetTomatoes() << "\n";
				}
				file.close();

				Sleep(1000);
			}

			if (int(choice == 51))
			{

				pn1.GetCheese() -= amount;
				ofstream file("ingrediyent.txt");
				file.setf(ios::left);

				if (file.is_open()) {
					file.clear();
					file << "Gobelek sayi: " << pn1.GetMushroom() << "\n";
					file << "Et sayi: " << pn1.GetMeat() << "\n";
					file << "Pendir sayi: " << pn1.GetCheese() << "\n";
					file << "Tomat sayi: " << pn1.GetTomatoes() << "\n";

				}
				file.close();
				Sleep(1000);
			}

			if (int(choice == 52))
			{

				pn1.GetTomatoes() -= amount;
				ofstream file("ingrediyent.txt");
				file.setf(ios::left);

				if (file.is_open()) {
					file.clear();
					file << "Gobelek sayi: " << pn1.GetMushroom() << "\n";
					file << "Et sayi: " << pn1.GetMeat() << "\n";
					file << "Pendir sayi: " << pn1.GetCheese() << "\n";
					file << "Tomat sayi: " << pn1.GetTomatoes() << "\n\n";

				}
				file.close();
				Sleep(1000);
			}


			cout << "\nYene elave edeceksiniz ?\n1.He\ \n2.Yox : ";
			cin >> sechim;
			if (sechim == 1)
			{
				continue;
			}
			else
			{
				break;
			}



			if (choice == '1') ptr->dish->addIngredient(new Mushrooms("Sampinyon", 10, 10, 10, 10), amount);
			else if (choice == '2') ptr->dish->addIngredient(new Meat("Et", 10, 10, 10, 10), amount);
			else if (choice == '3') ptr->dish->addIngredient(new Cheese("Holland Pendiri", 10, 10, 10, 10), amount);
			else if (choice == '4') ptr->dish->addIngredient(new Tomatoes("Cherry Pomidoru", 10, 10, 10, 10), amount);
		}
		else
		{
			return;
		}

	}
}


int start() {
	char choice;
	char sechim;
	int user_or_admin;
	string admin_user;
	int admin_password;
	AdminPanel admin;
	UserPanel user;
	while (true) {
		cout << "1.Admin(Login admin pass 1)\n2.User: ";
		cin >> user_or_admin;
		system("cls");
		cin.ignore();

		if (user_or_admin == 1)
		{
			string login;
			int pass;
			cout << "Admin logini daxil edin: ";
			cin >> login;
			cout << "Admin passwordu daxil edin: ";
			cin >> pass;

			cin.ignore();

			if (login != "admin" && pass != 1)
			{
				cout << "Admin login  veya shifre yalnishdir " << endl << endl;
			}
			if (login == "admin" && pass == 1)
			{
				system("cls");
				int sechim = 0;
				cout << "1.Qalan Butun ingrediyentler\n2.Userler\n3.Restoranin umumi budcesi: ";
				cin >> sechim;

				cin.ignore();

				if (sechim == 1)
				{
					system("cls");
					admin.check_all();
				}
				if (sechim == 2)
				{
					system("cls");
					admin.user();
				}
				if (sechim == 3)
				{
					system("cls");
					admin.Budce_bax();
				}


			}

		}

		if (user_or_admin == 2)
		{
			system("cls");
			int sign;
			cout << "1.SignUp\n2.SignIn\n";
			cin >> sign;

			cin.ignore();

			if (sign == 1)
			{

				user.SignUp();
			}
			if (sign == 2)
			{
				string login;
				int pass;
				system("cls");
				if (user.SignIn() == 1)
				{
					while (true) {
						menu();

						choice = _getch();


						if (choice == '1') {

							auto ptr = new Oven();
							cout << "Ingredients elave etmek isteyirsiz ? Y/N: ";
							sechim = _getch();
							if (sechim == 'y' || sechim == 'Y')
							{
								appendIngredients(ptr, admin);
								system("cls");
							}

							ptr->dish->printRecipe();
							ptr->cook();
							cout << " Davam etmek uchun enter duymesine basin.";
						}
						else if (choice == '2') {
							auto ptr = new Pot();
							cout << "Ingredients elave etmek isteyirsiz ? Y/N: ";
							sechim = _getch();
							if (sechim == 'y' || sechim == 'Y')
							{
								appendIngredients(ptr, admin);
								system("cls");
							}

							ptr->dish->printRecipe();
							ptr->cook();

						}
						else if (choice == '3') {
							auto ptr = new Brazier();
							cout << "Ingredients elave etmek isteyirsiz ? Y/N: ";
							sechim = _getch();
							if (sechim == 'y' || sechim == 'Y')
							{
								appendIngredients(ptr, admin);
								system("cls");
							}

							ptr->dish->printRecipe();
							ptr->cook();

						}
						else if (choice == '4') {
							cout << "Chixis olundu\n"; break;
						}
						else cout << "Wrong Choice!\n";

						system("pause");
						system("cls");
					}
				}
			}


		}

	}
}


int main() {
	start();

}
