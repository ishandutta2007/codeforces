#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 1e9 + 7;
int n, ct, cnt, top, dfn_cnt, time_now, c, pos[Maxn], prim[Maxn], a[Maxn], node[Maxn], dep[Maxn], sta[Maxn], head[Maxn], dfn[Maxn], Time[Maxn], anc[Maxn][20];
long long ans, tmp, F[Maxn], sum[Maxn], mu[Maxn], phi[Maxn];
bool vis[Maxn];
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void init_dfs(int u, int fa)
{
	dfn[u] = ++dfn_cnt;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dep[to] = dep[u] + 1, anc[to][0] = u, init_dfs(to, u);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
vector <int> G[Maxn];
void build(void)
{
	time_now++;
	sort(node + 1, node + 1 + ct, [](int x, int y){return dfn[x] < dfn[y];});
	top = 0;
	if (node[1] != 1) sta[++top] = 1; 
	for (int i = 1; i <= ct; i++)
	{
		if (!top)
		{
			sta[++top] = node[i];
			if (Time[node[i]] != time_now) G[node[i]].clear(), Time[node[i]] = time_now;
			continue;
		}
		int l = lca(node[i], sta[top]);
		if (Time[l] != time_now) Time[l] = time_now, G[l].clear();
		while (top > 1 && dep[sta[top - 1]] > dep[l]) G[sta[top - 1]].push_back(sta[top]), top--;
		if (dep[l] < dep[sta[top]]) G[l].push_back(sta[top]), top--;
		if (!top || sta[top] != l) sta[++top] = l;
		sta[++top] = node[i];
	}
	while (top > 1) G[sta[top - 1]].push_back(sta[top]), top--;
}
void dfs(int u, int d)
{
	if (a[u] % d == 0)
	{
		(tmp += p - phi[a[u]] * (long long) phi[a[u]] * dep[u] % p) %= p;
		sum[u] = phi[a[u]];
	}
	else sum[u] = 0;
	for (auto to : G[u])
	{
		dfs(to, d);
		(tmp += p - 2 * sum[u] * sum[to] % p * dep[u] % p) %= p;
		(sum[u] += sum[to]) %= p;
	}
}
void get_phi(void)
{
	mu[1] = phi[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) prim[++c] = i, phi[i] = i - 1, mu[i] = -1;
		for (int j = 1; j <= c && i * prim[j] <= n; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0)
			{
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			phi[i * prim[j]] = phi[i] * (prim[j] - 1);
			mu[i * prim[j]] = -mu[i];
		}
	}
}
int main()
{
	scanf("%d", &n);
	get_phi();
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), pos[a[i]] = i;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	init_dfs(1, 0), init();
	for (int i = 1; i <= n; i++)
	{
		ct = tmp = 0;
		for (int j = i; j <= n; j += i) node[++ct] = pos[j];
		build();
		dfs(1, i);
		for (int j = i; j <= n; j += i) (tmp += phi[j] * dep[pos[j]] % p * sum[1]) %= p;
		F[i] = 2 * tmp % p;
	}
	for (int i = 1; i <= n; i++)
	{
		long long d = i * get_inv(phi[i]) % p;
		for (int j = i; j <= n; j += i)
			(ans += d * F[j] % p * (p + mu[j / i])) %= p;
	}
	printf("%lld", ans * get_inv(n * (n - 1LL) % p) % p);
	return 0;
}