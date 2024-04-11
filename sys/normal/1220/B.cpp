#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, a[Maxn][Maxn], b[Maxn], g;
int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 2; i <= n; i++)
		g = gcd(a[1][i], g);
	int maxi = sqrt(g);
	for (int i = 1; i <= maxi; i++)
	{
		if (g % i == 0)
		{
			b[1] = i;
			for (int j = 2; j <= n; j++)
				b[j] = a[1][j] / i;
			for (int j = 2; j <= n; j++)
				for (int k = j + 1; k <= n; k++)
					if (b[j] * (long long) b[k] != a[j][k]) goto A;
			for (int i = 1; i <= n; i++)
				printf("%d ", b[i]);
			return 0;
			A:;
			b[1] = g / i;
			for (int j = 2; j <= n; j++)
				b[j] = a[1][j] / b[1];
			for (int j = 2; j <= n; j++)
				for (int k = j + 1; k <= n; k++)
					if (b[j] * (long long) b[k] != a[j][k]) goto B;
			for (int i = 1; i <= n; i++)
				printf("%d ", b[i]);
			return 0;
			B:;
		}
	}
	return 0;
}