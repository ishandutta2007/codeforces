#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int a[100020];
int b[100020];
int c[100020];
int f[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			f[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			f[F(a[i])] = F(b[i]);
			if (a[i] == b[i])
			{
				f[F(a[i])] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &c[i]);
			if (c[i])
			{
				f[F(c[i])] = 0;
			}
		}
		int z = 1;
		for (int i = 1; i <= n; i++)
		{
			if (F(i) == i)
			{
				z = z * 2 % 1000000007;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}