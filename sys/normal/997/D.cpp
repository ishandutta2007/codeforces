#include <bits/stdc++.h>
using namespace std;

const int Maxn = 4005, Maxk = 80, p = 998244353;
int n1, n2, k, cnt, ct, tot_siz, root, head[Maxn], siz[Maxn], maxi[Maxn], node[Maxn];
long long tot, ans[2][Maxk], C[Maxk][Maxk];
bool type, vis[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void get_root(int u, int fa)
{
	node[++ct] = u;
	maxi[u] = siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && !vis[to])
		{
			get_root(to, u);
			maxi[u] = max(maxi[u], siz[to]);
			siz[u] += siz[to];
		}
	}
	maxi[u] = max(maxi[u], tot_siz - siz[u]);
	if (maxi[u] < maxi[root]) root = u;
}
void dp(int u)
{
	static long long f[Maxk][Maxn], g[Maxk][Maxn];
	for (int i = 0; i <= k; i++)
		for (int j = 1; j <= ct; j++)
			f[i][node[j]] = g[i][node[j]] = 0;
	f[0][u] = g[0][u] = 1;
	for (int l = 1; l <= k; l++)
		for (int i = 1; i <= ct; i++)
			for (int j = head[node[i]]; j; j = edge[j].nxt)
			{
				(g[l][edge[j].to] += g[l - 1][node[i]]) %= p;
				if (edge[j].to != u)
					(f[l][edge[j].to] += f[l - 1][node[i]]) %= p;
			}
	for (int i = 1; i <= ct; i++)
		for (int j = 0; j <= k; j++)
			for (int l = 0; l <= k; l++)
				if (l + j <= k && node[i] != u)
					(ans[type][l + j] += f[l][node[i]] * g[j][node[i]]) %= p;
	for (int i = 0; i <= k; i++)
		(ans[type][i] += g[i][u]) %= p;
}
void divide(int u)
{
	vis[u] = true;
	dp(u);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!vis[to])
		{
			root = 0;
			ct = 0, get_root(to, u), tot_siz = siz[to], ct = 0, get_root(to, u);
			divide(root);
		}
	}
}
int main()
{
	scanf("%d%d%d", &n1, &n2, &k);
	C[0][0] = 1;
	for (int i = 1; i <= k; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	for (int i = 1; i < n1; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	maxi[0] = 0x3f3f3f3f;
	tot_siz = n1, get_root(1, 0);
	divide(root);
	type = true;
	cnt = 0;
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i < n2; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	tot_siz = n2, ct = 0, get_root(1, 0);
	divide(root);
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			if (i + j == k)
				(tot += ans[0][i] * ans[1][j] % p * C[k][i]) %= p;
	printf("%lld", tot);
	return 0;
}