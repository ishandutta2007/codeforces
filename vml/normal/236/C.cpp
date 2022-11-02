#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <set>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long long n;
	cin>> n;
	if(n == 1)
	{
		cout<<'1';
	}
	else if(n == 2)
	{
		cout<<'2';
	}
	else if(n % 2 == 1)
	{
		cout<< n * (n - 1) * (n - 2);
	}
	else if(n % 2 == 0)
	{
		if(n % 3 == 0)
		{
			cout<< (n - 1) * (n - 2) * (n - 3);
		}
		else
		{
			cout<< n * (n - 1) * (n - 3);
		}
	}
	return 0;
}