#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s;
int a[5];
char p[] = "BGR";

int main()
{
	cin >> n >> s;
	for (int i = 0; i < 3; i++)
		a[i] = 0;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		while(p[x] != s[i]) x++;
		a[x]++;
	}
	if (a[0] == 0 && a[1] == 0)
	{
		printf("%c\n", p[2]);
		return 0;
	}
	if (a[0] == 0 && a[2] == 0)
	{
		printf("%c\n", p[1]);
		return 0;
	}
	if (a[1] == 0 && a[2] == 0)
	{
		printf("%c\n", p[0]);
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		if (n - a[i] > 1)
			printf("%c", p[i]);
	}
	printf("\n");

	return 0;
}