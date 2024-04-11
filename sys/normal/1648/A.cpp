#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, a[405][Maxn], cnt[Maxn], cnt2[Maxn];
long long tmp, ans;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]), cnt2[a[i][j]]++;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			tmp -= 1LL * cnt[a[i][j]] * (cnt2[a[i][j]] - cnt[a[i][j]]);
			cnt[a[i][j]]++;
			tmp += 1LL * cnt[a[i][j]] * (cnt2[a[i][j]] - cnt[a[i][j]]);
		}
		ans += tmp;
	}
	tmp = 0, memset(cnt, 0, sizeof(cnt));
	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			tmp -= 1LL * cnt[a[i][j]] * (cnt2[a[i][j]] - cnt[a[i][j]]);
			cnt[a[i][j]]++;
			tmp += 1LL * cnt[a[i][j]] * (cnt2[a[i][j]] - cnt[a[i][j]]);
		}
		ans += tmp;
	}
	printf("%lld", ans);
	return 0;
}