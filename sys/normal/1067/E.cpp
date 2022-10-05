#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005, p = 998244353;
int n, cnt, head[Maxn], siz[Maxn];
long long ans, p2[Maxn], f[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	long long prod = 1;
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			(prod *= p2[siz[to] - 1] + f[to]) %= p;
			siz[u] += siz[to];
		}
	}
	(ans += p2[n - siz[u]] * (f[u] = (p + p2[siz[u] - 1] - prod) % p)) %= p;
}
int main()
{
	scanf("%d", &n);
	p2[0] = 1;
	for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % p;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	printf("%lld", ans * 2 % p);
	return 0;
}