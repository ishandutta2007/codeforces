#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;
int T, n, m, a[Maxn][Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		if (n == 1 && m == 1)
		{
			if (!a[1][1]) printf("Yes\n0\n");
			else puts("No");
			continue;
		}
		if (a[1][1] > 2 || a[1][m] > 2 || a[n][1] > 2 || a[n][m] > 2)
		{
			puts("No");
			continue;
		}
		for (int i = 1; i <= n; i++)
			if (a[i][1] > 3 || a[i][m] > 3)
			{
				puts("No");
				goto END;
			}
		for (int i = 1; i <= m; i++)
			if (a[1][i] > 3 || a[n][i] > 3)
			{
				puts("No");
				goto END;
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] > 4)
				{
					puts("No");
					goto END;
				}
		puts("Yes");
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d ", 4 - (i == 1 || i == n) - (j == 1 || j == m));
			puts("");
		}
		END:;
	}
	return 0;
}