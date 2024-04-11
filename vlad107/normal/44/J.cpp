#include <cstdio>
#include <memory.h>
#include <cstring>

#define N 1100

int n, m;
bool c[4];
char a[N][N];

bool good(char c)
{
	return c >= 0 && c < 4;
}

int main()
{
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++)
		gets(a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '.' || good(a[i][j]))
				continue;
			if (a[i][j] == 'w' && (j < m - 2 && a[i][j + 1] == 'b' && a[i][j + 2] == 'w'))
			{
				memset(c, true, sizeof(c));
				if (i)
				{
					if (good(a[i - 1][j]))
						c[a[i - 1][j]] = false;
					if (j < m - 1 && good(a[i - 1][j + 1]))
						c[a[i - 1][j + 1]] = false;
					if (j < m - 2 && good(a[i - 1][j + 2]))
						c[a[i - 1][j + 2]] = false;
				}
				if (j && good(a[i][j - 1]))
					c[a[i][j - 1]] = false;
				if (j < m - 3 && good(a[i][j + 3]))
					c[a[i][j + 3]] = false;
				for (int i2 = 0; i2 < 4; i2++)
					if (c[i2])
					{
						a[i][j + 1] = a[i][j + 2] = a[i][j] = i2;
						break;
					}
				if (!good(a[i][j]))
				{
					puts("NO");
					return 0;
				}
			}
			else if (a[i][j] == 'w' && (i < n - 2 && a[i + 1][j] == 'b' && a[i + 2][j] == 'w'))
			{
				memset(c, true, sizeof(c));
				if (i && good(a[i - 1][j]))
					c[a[i - 1][j]] = false;
				if (j)
				{
					if (good(a[i][j - 1]))
						c[a[i][j - 1]] = false;
					if (good(a[i + 1][j - 1]))
						c[a[i + 1][j - 1]] = false;
				}
				if (j < m - 1)
				{
					if (good(a[i][j + 1]))
						c[a[i][j + 1]] = false;
					if (good(a[i + 1][j + 1]))
						c[a[i + 1][j + 1]] = false;

				}
				for (int i2 = 0; i2 < 4; i2++)
					if (c[i2])
					{
						a[i + 2][j] = a[i + 1][j] = a[i][j] = i2;
						break;
					}
				if (!good(a[i][j]))
				{
					puts("NO");
					return 0;
				}
			}
			else
			{
				puts("NO");
				return 0;
			}
		}
	puts("YES");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%c", (good(a[i][j]) ? a[i][j] + 'a' : a[i][j]));
		puts("");
	}
}