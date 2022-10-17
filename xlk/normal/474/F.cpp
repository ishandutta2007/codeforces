#include <bits/stdc++.h>
using namespace std;
int n, q, x, l, r;
struct P
{
	int g, c;
} f[131073][17], z;
P F(P a, P b)
{
	int g = __gcd(a.g, b.g), c = (g == a.g ? a.c : 0) + (g == b.g ? b.c : 0);
	return {g, c};
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		f[i][0] = {x, 1};
	}
	for (int j = 1; j < 17; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			f[i][j] = F(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &l, &r);
		x = r - l + 1;
		z = {0, 0};
		for (int j = 16; j >= 0; j--)
		{
			if (l + (1 << j) <= r + 1)
			{
				z = F(z, f[l][j]);
				l += 1 << j;
			}
		}
		printf("%d\n", x - z.c);
	}
	return 0;
}