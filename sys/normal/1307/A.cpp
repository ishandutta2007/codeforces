#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int T, n, m, a[Maxn], ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		ans = a[1];
		for (int i = 2; i <= n; i++)
		{
			int tmp = a[i];
			a[i] -= min(m / (i - 1), a[i]);
			ans += tmp - a[i];
			m -= (tmp - a[i]) * (i - 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}