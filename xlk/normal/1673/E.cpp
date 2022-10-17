#include <bits/stdc++.h>
using namespace std;
int n, k;
int b[1050000];
int z[1050000];
int C(int n, int m)
{
	return (n & m) == m;
}
int G(int n, int m) // >= m
{
	if (m < 0)
	{
		return n == 0;
	}
	if (m > n)
	{
		return 0;
	}
	return C(n - 1, m - 1);
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		long long x = b[i], y = 0;
		int j = i;
		while (y < 20 && x << y < 1 << 20)
		{
			int u = n - 1 - (j - i);
			int v = k;
			if (i > 1)
			{
				u--;
				v--;
			}
			if (j < n)
			{
				u--;
				v--;
			}
			if (G(u, v))
			{
				z[x << y] ^= 1;
			}
			if (j < n)
			{
				y += b[++j];
			}
			else
			{
				break;
			}
		}
	}
	int l = (1 << 20) - 1;
	while (l > 0 && z[l] == 0)
	{
		l--;
	}
	for (int i = l; i >= 0; i--)
	{
		printf("%d", z[i]);
	}
	printf("\n");
	return 0;
}