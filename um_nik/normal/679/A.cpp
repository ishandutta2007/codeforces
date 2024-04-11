#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

bool isPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}

bool query(int x)
{
	cout << x << endl;
	string s;
	cin >> s;
	return s == "yes";
}

void solve(int minP)
{
	for (int x = minP; minP * x <= 100; x++)
	{
		if (!isPrime(x)) continue;
		if (query(x * minP))
		{
			cout << "composite" << endl;
			return;
		}
	}
	cout << "prime" << endl;
}

int main()
{
	for (int x = 2; x < 10; x++)
	{
		if (!isPrime(x)) continue;
		if (query(x))
		{
			solve(x);
			return 0;
		}
	}
	cout << "prime" << endl;

	return 0;
}