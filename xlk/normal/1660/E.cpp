#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[2020][2020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int s[2020] = {};
		int c = 0, z = n * n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%1d", &a[i][j]);
				c += a[i][j];
				s[(i + n - j) % n] += a[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			int u = c - s[i] + (n - s[i]);
			z = min(z, u);
		}
		printf("%d\n", z);
	}
	return 0;
}