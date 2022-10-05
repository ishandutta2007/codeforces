#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;
int T, n, ans, a[Maxn], f[Maxn][Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				f[i][j] = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) f[1][i] = 0;
		for (int i = 1; i <= n; i++)
		{
			int cnt = 0;
			for (int j = i - 1; j >= 1; j--)
				if (j + a[j] >= i)
				{
					f[i][j + a[j]] = min(f[i][j + a[j]], f[j][i - 1] + cnt);
					cnt++;
				}
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][j - 1]);
		}
		printf("%d\n", f[n][n]);
	}
	return 0;
}