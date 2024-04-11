#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int t, n;
long long a[500020];
int c[70];
long long b[70];
int main()
{
	scanf("%d", &t);
	for (int i = 0; i < 63; i++)
	{
		b[i] = (1LL << i) % mod;
	}
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			for (int j = 0; j < 60; j++)
			{
				if (a[i] >> j & 1)
				{
					c[j]++;
				}
			}
		}
		long long z = 0;
		for (int i = 0; i < n; i++)
		{
			long long ds = 0;
			for (int k = 0; k < 60; k++)
			{
				if (a[i] >> k & 1)
				{
					ds = (ds + b[k] * n) % mod;
				}
				else
				{
					ds = (ds + b[k] * c[k]) % mod;
				}
			}
			for (int j = 0; j < 60; j++)
			{
				if (a[i] >> j & 1)
				{
					z = (z + b[j] * c[j] % mod * ds) % mod;
				}
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}