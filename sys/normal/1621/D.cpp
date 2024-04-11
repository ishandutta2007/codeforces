#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
int T, n, c[Maxn][Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0x3f3f3f3f;
		long long tot = 0;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++)
			for (int j = 1; j <= 2 * n; j++)
				scanf("%d", &c[i][j]);
		for (int i = n + 1; i <= 2 * n; i++)
			for (int j = n + 1; j <= 2 * n; j++)
				tot += c[i][j];
		ans = min(ans, c[1][n + 1]);
		ans = min(ans, c[n][n + 1]);
		ans = min(ans, c[n + 1][1]);
		ans = min(ans, c[n + 1][n]);
		ans = min(ans, c[2 * n][1]);
		ans = min(ans, c[1][2 * n]);
		ans = min(ans, c[n][2 * n]);
		ans = min(ans, c[2 * n][n]);
		printf("%lld\n", ans + tot);
	}
	return 0;
}