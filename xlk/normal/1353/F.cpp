#include <bits/stdc++.h>
using namespace std;
int t, n, m;
long long a[102][102];
long long f[102][102];
long long l[10002];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		int lc = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				a[i][j] -= i + j;
				l[lc++] = a[i][j];
			}
		}
		sort(l, l + lc);
		lc = unique(l, l + lc) - l;
		long long ans = 1e18;
		memset(f, 0x3f, sizeof f);
		f[0][1] = 0;
		for (int k = lc - 1; k >= 0; k--)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (a[i][j] >= l[k])
					{
						f[i][j] = min(f[i-1][j], f[i][j-1]) + a[i][j];
					}
				}
			}
			ans = min(ans, f[n][m] - (n + m - 1) * l[k]);
		}
		cout << ans << endl;
	}
	return 0;
}