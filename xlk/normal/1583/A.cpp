#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int s = 0, p = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			s += x;
			if (x & 1)
			{
				p = i;
			}
		}
		if (isPrime(s))
		{
			cout << n - 1 << endl;
			for (int i = 1; i <= n; i++)
			{
				if (i != p)
				{
					cout << i << ' ';
				}
			}
			cout << endl;
		}
		else
		{
			cout << n << endl;
			for (int i = 1; i <= n; i++)
			{
				cout << i << ' ';
			}
			cout << endl;
		}
	}
}