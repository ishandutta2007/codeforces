#include <bits/stdc++.h>
using namespace std;
int n, m, q, c, z;
char s[1020][1020];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '*')
			{
				c++;
			}
		}
	}
	for (int i = 0; i < c; i++)
	{
		if (s[i % n][i / n] == '.')
		{
			z++;
		}
	}
	for (int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if (s[x][y] == '.')
		{
			if (s[c % n][c / n] == '.')
			{
				z++;
			}
			c++;
		}
		else
		{
			c--;
			if (s[c % n][c / n] == '.')
			{
				z--;
			}
		}
		if (s[x][y] == '.')
		{
			s[x][y] = '*';
			if (y * n + x < c)
			{
				z--;
			}
		}
		else
		{
			s[x][y] = '.';
			if (y * n + x < c)
			{
				z++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}