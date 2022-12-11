#include <bits/stdc++.h>
using namespace std;

char dat[55][55];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", dat[i]);

	int ans = 1e9;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (i == j || j == k || i == k) continue;

				int a1 = 1e8, a2 = 1e8, a3 = 1e8;
				for (int p = 0; p < m; p++) if (isdigit(dat[i][p])) a1 = min({ a1, p, m - p });
				for (int p = 0; p < m; p++) if (isalpha(dat[j][p])) a2 = min({ a2, p, m - p });
				for (int p = 0; p < m; p++) if (!isalnum(dat[k][p])) a3 = min({ a3, p, m - p });
				ans = min(ans, a1 + a2 + a3);
			}
		}
	}

	printf("%d\n", ans);
}