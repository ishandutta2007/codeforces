#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 125005;
int n, m, ct, ans = 2e9 + 1, a[Maxn][6], ord[Maxn], rk[Maxn], w[Maxn], tmp[Maxn];
bitset <25005> Bi[Maxn];
void work(int lt, int rt)
{
	int mini = 0x3f3f3f3f;
	ct = 0;
	if (lt > n || lt > rt) return ;
	for (int i = lt; i <= rt; i++) ord[i] = i, mini = min(mini, w[i]);
	sort(ord + lt, ord + rt + 1, [](int x, int y){return w[x] < w[y];});
	memset(rk, 0, sizeof(int[n + 1]));
	for (int i = lt; i <= rt; i++) rk[ord[i]] = i;
	for (int i = lt; i <= rt; i++)
		for (int j = 1; j <= m; j++)
			tmp[++ct] = a[i][j];
	sort(tmp + 1, tmp + 1 + ct);
	ct = unique(tmp + 1, tmp + 1 + ct) - tmp - 1;
	for (int i = lt; i <= rt; i++)
		for (int j = 1; j <= m; j++)
			Bi[lower_bound(tmp + 1, tmp + 1 + ct, a[i][j]) - tmp][rk[i] - lt] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (ans <= mini + w[i]) continue;
		bitset <25005> now;
		for (int j = 1; j <= m; j++)
			now |= Bi[lower_bound(tmp + 1, tmp + 1 + ct, a[i][j]) - tmp];
		if ((int) now.count() != rt - lt + 1)
			ans = min(ans, w[i] + w[ord[(~now)._Find_first() + lt]]);
	}
	for (int i = 1; i <= ct; i++) Bi[i].reset();
}
int main()
{
	w[0] = 0x3f3f3f3f;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= 4; i++)
		work((i - 1) * 25000 + 1, min(n, i * 25000));
	printf("%d", ans == 2e9 + 1 ? -1 : ans);
	return 0;
}