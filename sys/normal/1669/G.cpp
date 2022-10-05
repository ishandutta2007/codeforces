#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55;
int T, n, m, a[Maxn][Maxn], b[Maxn][Maxn], c[Maxn][Maxn], cnt[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				char ch = getchar();
				while (ch != '.' && ch != '*' && ch != 'o') ch = getchar();
				a[i][j] = ch == '.' ? 0 : (ch == '*' ? 1 : 2), b[i][j] = c[i][j] = cnt[j] = 0;
			}
		for (int j = 1; j <= m; j++) a[n + 1][j] = 2;
		for (int i = 1; i <= n + 1; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] == 2) c[i][j] = cnt[j], cnt[j] = 0;
				else cnt[j] += a[i][j];
		for (int i = 1; i <= n + 1; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] == 2)
				{
					b[i][j] = 2;
					for (int k = 1; k <= c[i][j]; k++)
						b[i - k][j] = 1;
				}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				putchar(!b[i][j] ? '.' : (b[i][j] == 1 ? '*' : 'o'));
			puts("");
		}
	}
	return 0;
}