#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7, Maxn = 4105;
int n, m, maxi, cnt, tot, head[Maxn], S[13][13], f[1055][13][Maxn];
long long get_inv(long long x)
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
int init_dfs(int u, int fa)
{
	int sta = 1 << (u - n - 1);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) sta |= init_dfs(to, u);
	}
	return sta;
}
void dfs(int u, int fa)
{
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= maxi; j++)
			f[u][i][j] = 0;
	for (int i = 1; i <= m; i++)
		f[u][i][1 << (i - 1)] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			for (int s = maxi; s >= 0; s--)
				for (int j = 1; j <= m; j++)
					if (s & (1 << (j - 1)))
						for (int k = head[j + n]; k; k = edge[k].nxt)
							if (!(s & S[j][edge[k].to - n])) (f[u][j][s | S[j][edge[k].to - n]] += f[u][j][s] * (long long) f[to][edge[k].to - n][S[j][edge[k].to - n]] % p) %= p;
		}
	}
	for (int i = 1; i <= m; i++)
		(tot += f[u][i][maxi]) %= p;
}
int work(int root)
{
	tot = 0;
	dfs(root, 0);
	return tot;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y), add(x, y), add(y, x);
	}
	scanf("%d", &m);
	for (int i = 1; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y), add(x + n, y + n), add(y + n, x + n);
	}
	maxi = (1 << m) - 1;
	for (int i = n + 1; i <= n + m; i++)
		for (int j = n + 1; j <= n + m; j++)
			if (i != j) S[i - n][j - n] = init_dfs(j, i);
	printf("%lld", work(1) * get_inv(work(n + 1)) % p);
	return 0;
}