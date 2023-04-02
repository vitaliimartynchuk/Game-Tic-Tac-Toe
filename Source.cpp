#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

int x, y;
int step = 0;
bool userWIN = false, botWIN = false, noWIN = false;

const int ROWS = 3;
const int COLS = 3;
const char Emptiness = ' ';
const char User_symbol = 'x';
const char Bot_symbol = 'o';

char field[ROWS][COLS];

const char Vertical = 179;
const char Horizontal = 196;
const char TopStart = 218;
const char TopCenter = 194;
const char TopEnd = 191;
const char MiddleStart = 195;
const char MiddleCenter = 197;
const char MiddleEnd = 180;
const char BottomStart = 192;
const char BottomCenter = 193;
const char BottomEnd = 217;

void fill_arr()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			field[i][j] = Emptiness;
		}
	}
}

void board()
{
	system("cls");

	cout << "GAME TICK TACK TOE" << endl;
	cout << "    1.  2.  3." << endl;

	cout << "  ";
	for (int i = 1; i <= 10; i++)
	{
		if (i == 1)
		{
			cout << TopStart;
		}
		if (i == 4)
		{
			cout << TopCenter;
		}
		if (i == 7)
		{
			cout << TopCenter;
		}
		if (i == 10)
		{
			cout << TopEnd;
		}
		else
		{
			cout << Horizontal;
		}
	}
	cout << endl;

	cout << "1." << Vertical << " " << field[0][0] << " " << Vertical  << " " << field[0][1] << " " << Vertical << " " << field[0][2] << " " << Vertical << endl;

	cout << "  ";
	for (int i = 1; i <= 10; i++)
	{
		if (i == 1)
		{
			cout << MiddleStart;
		}
		if (i == 4)
		{
			cout << MiddleCenter;
		}
		if (i == 7)
		{
			cout << MiddleCenter;
		}
		if (i == 10)
		{
			cout << MiddleEnd;
		}
		else
		{
			cout << Horizontal;
		}
	}
	cout << endl;

	cout << "2." << Vertical << " " << field[1][0] << " " << Vertical << " " << field[1][1] << " " << Vertical << " " << field[1][2] << " " << Vertical << endl;

	cout << "  ";
	for (int i = 1; i <= 10; i++)
	{
		if (i == 1)
		{
			cout << MiddleStart;
		}
		if (i == 4)
		{
			cout << MiddleCenter;
		}
		if (i == 7)
		{
			cout << MiddleCenter;
		}
		if (i == 10)
		{
			cout << MiddleEnd;
		}
		else
		{
			cout << Horizontal;
		}
	}
	cout << endl;

	cout << "3." << Vertical << " " << field[2][0] << " " << Vertical << " " << field[2][1] << " " << Vertical << " " << field[2][2] << " " << Vertical << endl;

	cout << "  ";
	for (int i = 1; i <= 10; i++)
	{
		if (i == 1)
		{
			cout << BottomStart;
		}
		if (i == 4)
		{
			cout << BottomCenter;
		}
		if (i == 7)
		{
			cout << BottomCenter;
		}
		if (i == 10)
		{
			cout << BottomEnd;
		}
		else
		{
			cout << Horizontal;
		}
	}
}

void user_step()
{
	cout << endl;
	cout << "Enter the row number (1-3): ";
	cin >> x;
	cout << "Enter the column number (1-3): ";
	cin >> y;
	while (field[x - 1][y - 1] != Emptiness || x < 1 || x > 3 || y < 1 || y > 3)
	{
		cout << "Error: a move is impossible" << endl;
		cout << "Enter the row number (1-3): ";
		cin >> x;
		cout << "Enter the column number (1-3): ";
		cin >> y;
	}
	field[x - 1][y - 1] = User_symbol;
	step++;
}

void bot_step()
{
	if (step != 9)
	{
		do
		{
			x = rand() % 3;
			y = rand() % 3;
		} while (field[x][y] != Emptiness);
		field[x][y] = Bot_symbol;
		step++;
	}
}

void who_win()
{
	if (
		(field[0][0] == User_symbol && field[0][1] == User_symbol && field[0][2] == User_symbol) ||
		(field[1][0] == User_symbol && field[1][1] == User_symbol && field[1][2] == User_symbol) ||
		(field[2][0] == User_symbol && field[2][1] == User_symbol && field[2][2] == User_symbol) ||

		(field[0][0] == User_symbol && field[1][0] == User_symbol && field[2][0] == User_symbol) ||
		(field[0][1] == User_symbol && field[1][1] == User_symbol && field[2][1] == User_symbol) ||
		(field[0][2] == User_symbol && field[1][2] == User_symbol && field[2][2] == User_symbol) ||

		(field[0][0] == User_symbol && field[1][1] == User_symbol && field[2][2] == User_symbol) ||
		(field[0][2] == User_symbol && field[1][1] == User_symbol && field[2][0] == User_symbol)
		)
	{
		userWIN = true;
	}
	if (
		(field[0][0] == Bot_symbol && field[0][1] == Bot_symbol && field[0][2] == Bot_symbol) ||
		(field[1][0] == Bot_symbol && field[1][1] == Bot_symbol && field[1][2] == Bot_symbol) ||
		(field[2][0] == Bot_symbol && field[2][1] == Bot_symbol && field[2][2] == Bot_symbol) ||

		(field[0][0] == Bot_symbol && field[1][0] == Bot_symbol && field[2][0] == Bot_symbol) ||
		(field[0][1] == Bot_symbol && field[1][1] == Bot_symbol && field[2][1] == Bot_symbol) ||
		(field[0][2] == Bot_symbol && field[1][2] == Bot_symbol && field[2][2] == Bot_symbol) ||

		(field[0][0] == Bot_symbol && field[1][1] == Bot_symbol && field[2][2] == Bot_symbol) ||
		(field[0][2] == Bot_symbol && field[1][1] == Bot_symbol && field[2][0] == Bot_symbol)
		)
	{
		botWIN = true;
	}
	if (userWIN == false && botWIN == false && step == 9 || userWIN == true && botWIN == true && step == 9)
	{
		noWIN = true;
	}
}

void reset()
{
	step = 0;
	userWIN = false, botWIN = false, noWIN = false;
}

void run_game()
{
	fill_arr();
	board();
	do
	{
		srand(time(NULL));

		board();

		user_step();

		board();

		cout << "\nLoading... (bot step)\n";
		Sleep(1500);

		bot_step();

		board();

		who_win();

	} while (userWIN == false && botWIN == false && noWIN == false);

	if (userWIN == true)
	{
		cout << "\nYOU WIN!\n\n";
	}
	if (botWIN == true)
	{
		cout << "\nYOU LOSE!\n\n";
	}
	if (noWIN == true)
	{
		cout << "\nDRAW!\n\n";
	}
	reset();
}

void menu()
{
	int choice;
	do
	{
		cout << "Menu:" << endl;
		cout << "1.Start GAME TICK TACK TOE" << endl;
		cout << "0.Exit" << endl;
		cout << "Enter number of Menu: "; cin >> choice;
		if (choice == 1)
		{
			cout << "\nLoading game...\n";
			Sleep(3000);
			run_game();
		}
		else if (choice != 0)
		{
			cout << "\nError: You entered an incorrect menu number" << endl;
		}
	} while (choice != 0);
}

void main()
{
	menu();
}