#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, z, a[520], f[520][520];
char c;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == '+')
		{
			cin >> a[i];
		}
		else
		{
			a[i] = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			memset(f, 0, sizeof f);
			f[0][0] = 1;
			int m = 1;
			for (int j = 0; j < n; j++)
			{
				if (j == i)
				{
					for (int k = 0; k < m; k++)
					{
						f[j + 1][k] = f[j][k] % p;
					}
				}
				else if (a[j] == -1)
				{
					for (int k = 0; k < m; k++)
					{
						f[j + 1][k] = (f[j + 1][k] + f[j][k]) % p;
						if (k > 0 || j < i)
						{
							f[j + 1][max(k - 1, 0)] = (f[j + 1][max(k - 1, 0)] + f[j][k]) % p;
						}
					}
				}
				else if (a[j] < a[i] || (a[j] == a[i] && j < i))
				{
					for (int k = 0; k < m; k++)
					{
						f[j + 1][k] = (f[j + 1][k] + f[j][k]) % p;
						f[j + 1][k + 1] = (f[j + 1][k + 1] + f[j][k]) % p;
					}
					m++;
				}
				else
				{
					for (int k = 0; k < m; k++)
					{
						f[j + 1][k] = f[j][k] * 2 % p;
					}
				}
			}
			int c = 0;
			for (int k = 0; k < m; k++)
			{
				c = (c + f[n][k]) % p;
			}
			z = (z + (long long)a[i] * c) % p;
		}
	}
	cout << z << endl;
	return 0;
}