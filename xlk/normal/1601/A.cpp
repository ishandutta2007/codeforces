#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int c[30] = {};
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			for (int j = 0; j < 30; j++)
			{
				if (x >> j & 1)
				{
					c[j]++;
				}
			}
		}
		int g = 0;
		for (int i = 0; i < 30; i++)
		{
			g = __gcd(g, c[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (g % i == 0)
			{
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}