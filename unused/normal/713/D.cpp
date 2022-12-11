#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

char dat[1005][1005];
short dp[1005][1005];

short sparse[10][10][1005][1005];

#ifdef _MSC_VER
#define __builtin_clz(x) (31 - __lzcnt(x))
#endif

short sparse_query(int sx, int sy, int ex, int ey)
{
	int k1 = 31 - __builtin_clz(ex - sx + 1), k2 = 31 - __builtin_clz(ey - sy + 1);
	return max(max(
		sparse[k1][k2][sx][sy],
		sparse[k1][k2][ex - (1 << k1) + 1][sy]
		),
		max(
		sparse[k1][k2][sx][ey - (1 << k2) + 1],
		sparse[k1][k2][ex - (1 << k1) + 1][ey - (1 << k2) + 1]
		));
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int tmp; scanf("%d", &tmp);
			dat[i][j] = (char)tmp;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dat[i][j] == 0) dp[i][j] = 0;
			else
			{
				short b = dp[i - 1][j], c = dp[i][j - 1];
				if (b != c) dp[i][j] = min(b, c) + 1;
				else dp[i][j] = b + dat[i - b][j - b];
			}

			sparse[0][0][i][j] = dp[i][j];
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= n - (1 << i) + 1; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				sparse[i][0][j][k] = max(
					sparse[i - 1][0][j][k],
					sparse[i - 1][0][j + (1 << (i - 1))][k]
					);
			}
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= n - (1 << i) + 1; k++)
			{
				for (int l = 1; l <= m - (1 << j) + 1; l++)
				{
					sparse[i][j][k][l] = max(
						sparse[i][j - 1][k][l],
						sparse[i][j - 1][k][l + (1 << (j - 1))]
						);
				}
			}
		}
	}

	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int lo = 1, hi = min(x2 - x1, y2 - y1) + 1, ans = 0;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			int res = sparse_query(x1 + mid - 1, y1 + mid - 1, x2, y2);
			if (res >= mid)
			{
				ans = mid;
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
}