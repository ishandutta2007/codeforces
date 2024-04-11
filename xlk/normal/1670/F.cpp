#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
long long l, r, z;
int c[1020][1020];
long long f[2020];
long long g[2020];
int F(int n, long long r, long long z)
{
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = 0; i < 60; i++)
	{
		memset(g, 0, sizeof g);
		for (int j = 0; j <= n; j++)
		{
			for (int k = z >> i & 1; k <= n; k += 2)
			{
				g[j + k] = (g[j + k] + f[j] * c[n][k]) % p;
			}
		}
		memset(f, 0, sizeof f);
		for (int j = 0; j <= 2 * n; j++)
		{
			int k = (j + 1 - (r >> i & 1)) / 2;
			f[k] = (f[k] + g[j]) % p;
		}
	}
	return f[0];
}
int main()
{
	for (int i = 0; i <= 1000; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	cin >> n >> l >> r >> z;
	cout << (F(n, r, z) + p - F(n, l - 1, z)) % p << endl;
	return 0;
}