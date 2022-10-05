#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m, ct;
long long val[Maxn];
set <int> Se1, Se2;
struct Ans
{
	int x, y;
	long long w;
}ans[2 * Maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		val[x] += w, val[y] -= w;
	}
	for (int i = 1; i <= n; i++)
	{
		if (val[i] > 0) Se1.insert(i);
		if (val[i] < 0) Se2.insert(i);
	}
	while (Se1.size() && Se2.size())
	{
		int x = *Se1.begin(), y = *Se2.begin();
		long long now = min(val[x], -val[y]);
		ans[++ct] = (Ans){x, y, now};
		val[x] -= now, val[y] += now;
		if (!val[x]) Se1.erase(Se1.begin());
		if (!val[y]) Se2.erase(Se2.begin());
	}
	printf("%d\n", ct);
	for (int i = 1; i <= ct; i++)
		printf("%d %d %lld\n", ans[i].x, ans[i].y, ans[i].w);
	return 0;
}