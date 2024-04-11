#include <iostream>
using namespace std;

char s[60][100] =
{
	"",
	"Washington",
	"Adams",
	"Jefferson",
	"Madison",
	"Monroe",
	"Adams",
	"Jackson",
	"Van Buren",
	"Harrison",
	"Tyler",
	"Polk",
	"Taylor",
	"Fillmore",
	"Pierce",
	"Buchanan",
	"Lincoln",
	"Johnson",
	"Grant",
	"Hayes",
	"Garfield",
	"Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge", "Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford", "Carter", "Reagan", "Bush", "Clinton"};

int main()
{
	int n;
	cin >> n;
	cout << s[n] << endl;

	return 0;
}