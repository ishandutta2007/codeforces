#include <bits/stdc++.h>
char s[300][300];
int t, n, m, z, c;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
void F(int x, int y)
{
	s[x][y] = 0;
	c++;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in(nx, ny) && s[nx][ny] == '1')
		{
			F(nx, ny);
		}
	}
}
int C(int x, int y, int d, int k)
{
	for (int i = 0; i <= d; i++)
	{
		int nx = x + dx[k] * i;
		int ny = y + dy[k] * i;
		if (!in(nx, ny) || s[nx][ny])
		{
			return 0;
		}
		nx = x + dx[k ^ 1] * i;
		ny = y + dy[k ^ 1] * i;
		if (!in(nx, ny) || s[nx][ny])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == '1')
				{
					c = 0;
					F(i, j);
					if (c & 3)
					{
						continue;
					}
					z += C(i, j, c / 4, 0) && C(i + c / 4, j + c / 4, c / 4, 2);
					z += C(i, j, c / 4, 4) && C(i + c / 2, j, c / 4, 6);
				}
			}
		}
		printf("%d\n", z);
	}
	return 0;
}