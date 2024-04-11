#include <iostream>
#include <fstream>
#include <string>

#define cin aushduha
#define cout oaijsiodja

int n, m;

int main()
{
	std::ifstream cin;
	std::ofstream cout;
	cin.open("input.txt");
	cout.open("output.txt");
	cin >> n >> m;
	if(m>n)
	{
		cout << "G";
		m--;
	}
	while(m>0 && n>0)
	{
		cout << "BG";
		m--;n--;
	}
	while(m>0)
	{
		cout << "G";
		m--;
	}
	while(n>0)
	{
		cout << "B";
		n--;
	}
	cout << '\n';
}