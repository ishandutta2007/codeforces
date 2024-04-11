#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 505;
char ch[Maxn][Maxn];
int T, n, m;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n + 1; i++)
			for (int j = 1; j <= m + 1; j++)
				ch[i][j] = '.';
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				ch[i][j] = getchar();
				while (ch[i][j] != 'X' && ch[i][j] != '.') ch[i][j] = getchar();
			}
		if (n % 3)
		{
			for (int i = 1; i <= n; i += 3)
				for (int j = 1; j <= m; j++)
					ch[i][j] = 'X';
			for (int i = 2; i <= n; i += 3)
			{
				int pos = 1;
				for (int j = 1; j <= m; j++)
					if (ch[i][j] == 'X') pos = j;
				for (int j = 1; j <= m; j++)
					if (ch[i + 1][j] == 'X') pos = j;
				ch[i][pos] = ch[i + 1][pos] = 'X';
			}
		}
		else
		{
			for (int i = 2; i <= n; i += 3)
				for (int j = 1; j <= m; j++)
					ch[i][j] = 'X';
			for (int i = 3; i <= n; i += 3)
			{
				int pos = 1;
				for (int j = 1; j <= m; j++)
					if (ch[i][j] == 'X') pos = j;
				for (int j = 1; j <= m; j++)
					if (ch[i + 1][j] == 'X') pos = j;
				ch[i][pos] = ch[i + 1][pos] = 'X';
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				putchar(ch[i][j]);
			puts("");
		}
	}
	return 0;
}