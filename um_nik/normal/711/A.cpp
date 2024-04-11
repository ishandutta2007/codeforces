#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int N = 1010;
int n;
string a[N];

void printAns()
{
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (a[i][0] == 'O' && a[i][1] == 'O')
		{
			a[i][0] = '+';
			a[i][1] = '+';
			printAns();
			return 0;
		}
		if (a[i][3] == 'O' && a[i][4] == 'O')
		{
			a[i][4] = '+';
			a[i][3] = '+';
			printAns();
			return 0;
		}
	}
	cout << "NO\n";


	return 0;
}