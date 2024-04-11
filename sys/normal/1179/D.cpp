#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005;
int n, cnt, top, sta[Maxn], siz[Maxn], head[Maxn];
long long ans = 0x3f3f3f3f3f3f3f3fLL, f[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
double slope(pair <long long, long long> x, pair <long long, long long> y)
{
	return (x.second - y.second) / (double) (x.first - y.first);
}
void dfs(int u, int fa)
{
	vector <pair <long long, long long> > Ve;
	Ve.clear();
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			siz[u] += siz[to];
			Ve.push_back(make_pair(siz[to], f[to] + siz[to] * (long long) siz[to] - 2LL * n * siz[to]));
		}
	}
	sort(Ve.begin(), Ve.end());
	top = 0;
	for (int i = 0; i < (int) Ve.size(); i++)
	{
		while (top > 1 && slope(Ve[sta[top - 1]], Ve[sta[top]]) >= -2 * Ve[i].first) top--;
		if (top) ans = min(ans, (long long) n * n + Ve[sta[top]].second + Ve[i].second + 2 * Ve[sta[top]].first * Ve[i].first);
		while (top > 1 && slope(Ve[sta[top - 1]], Ve[sta[top]]) >= slope(Ve[sta[top]], Ve[i])) top--;
		sta[++top] = i;
	}
	f[u] = siz[u] * (long long) siz[u];
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			f[u] = min(f[u], f[to] + (long long) (siz[u] - siz[to]) * (siz[u] - siz[to]));
	}
	ans = min(ans, f[u] + (n - siz[u]) * (long long) (n - siz[u]));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	printf("%lld", n * (n - 1LL) / 2 + ((long long) n * n - ans) / 2);
	return 0;
}