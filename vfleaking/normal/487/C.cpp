#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int n;
bool hasSol;
int a[MaxN];

void calc()
{
	if (n == 1)
	{
		hasSol = true;
		a[0] = 1;
	}
	else if (n == 4)
	{
		hasSol = true;
		a[0] = 1;
		a[1] = 3;
		a[2] = 2;
		a[3] = 4;
	}
	else
	{
		hasSol = true;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
			{
				hasSol = false;
				break;
			}
		if (!hasSol)
			return;

		int g = 2;
		while (true)
		{
			static bool book[MaxN];
			for (int i = 0; i < n; i++)
				book[i] = false;
			for (int i = 0, p = 1; i < n; i++, p = (s64)p * g % n)
				book[p] = true;
			if (count(book, book + n, true) == n - 1)
				break;

			g++;
		}

		static int gpow[MaxN];
		gpow[0] = 1;
		for (int i = 1; i < n; i++)
			gpow[i] = (s64)gpow[i - 1] * g % n;
		a[0] = 1;
		for (int i = 1; i < n - 1; i++)
			a[i] = i % 2 == 1 ? gpow[i] : gpow[n - 1 - i];
		a[n - 1] = n;
	}
}

int main()
{
	cin >> n;

	calc();

	if (hasSol)
	{
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
			printf("%d\n", a[i]);
	}
	else
		cout << "NO" << endl;

	return 0;
}