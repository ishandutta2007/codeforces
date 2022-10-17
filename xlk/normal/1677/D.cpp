#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int t, n, m;
int a[1000020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int f = 0;
		for (int i = n - m; i < n; i++)
		{
			if (a[i] > 0)
			{
				f = 1;
			}
		}
		if (f)
		{
			puts("0");
			continue;
		}
		long long z = 1;
		for (int i = 0; i < m; i++)
		{
			z = z * (i + 1) % p;
		}
		for (int i = 0; i < n - m; i++)
		{
			if (a[i] > m + i)
			{
				z = 0;
			}
			else if (a[i] == -1)
			{
				z = z * (m + i + 1) % p;
			}
			else if (a[i] == 0)
			{
				z = z * (m + 1) % p;
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}