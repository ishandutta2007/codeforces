#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string a[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int getNum()
{
	string s;
	cin >> s;
	int p = 0;
	while(p < 7 && a[p] != s) p++;
	if (p == 7) throw;
	return p;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int x = getNum();
	x = getNum() - x;
	x += 7;
	x %= 7;
	if (x == 0 || x == 2 || x == 3)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}