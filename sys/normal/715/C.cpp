#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, p, phi, cnt, son[Maxn], siz[Maxn], dep[Maxn], head[Maxn];
long long ans, dis1[Maxn], dis2[Maxn], P10[Maxn], inv_P10[Maxn];
map <int, int> Ma1, Ma2;
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void init_dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dis1[to] = (dis1[u] * 10 + edge[i].w) % p;
			dis2[to] = (dis2[u] + edge[i].w * P10[dep[u]]) % p;
			init_dfs(to, u);
			siz[u] += siz[to];
			if (siz[son[u]] < siz[to]) son[u] = to;
		}
	}
}
void cal(int u, int fa, int l)
{
	ans += Ma1[(dis2[l] + p - dis1[u] * P10[2 * dep[l]] % p * inv_P10[dep[u]] % p + dis1[l] * P10[dep[l]] % p) % p];
	ans += Ma2[(dis1[l] * inv_P10[dep[l]] % p + p - (dis2[u] - dis2[l] + p) * inv_P10[2 * dep[l]] % p) % p];
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) cal(to, u, l);
	}
}
void insert(int u, int fa)
{
	Ma1[dis2[u]]++, Ma2[dis1[u] * inv_P10[dep[u]] % p]++;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) insert(to, u);
	}
}
void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && to != son[u])
			dfs(to, u), Ma1.clear(), Ma2.clear();
	}
	if (son[u]) dfs(son[u], u);
	ans += Ma1[(dis2[u] + p - dis1[u] * P10[2 * dep[u]] % p * inv_P10[dep[u]] % p + dis1[u] * P10[dep[u]] % p) % p];
	ans += Ma2[(dis1[u] * inv_P10[dep[u]] % p + p - (dis2[u] - dis2[u] + p) * inv_P10[2 * dep[u]] % p) % p];
	Ma1[dis2[u]]++, Ma2[dis1[u] * inv_P10[dep[u]] % p]++;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && to != son[u])
			cal(to, u, u), insert(to, u);
	}
}
int main()
{
	dep[0] = -1;
	scanf("%d%d", &n, &p), phi = p;
	int tmp = p, maxi = sqrt(p);
	for (int i = 2; i <= maxi; i++)
		if (tmp % i == 0)
		{
			while (tmp % i == 0) tmp /= i;
			phi = phi / i * (i - 1);
		}
	if (tmp != 1) phi = phi / tmp * (tmp - 1);
	P10[0] = inv_P10[0] = 1;
	inv_P10[1] = fast_pow(10, phi - 1);
	for (int i = 1; i <= 2 * n; i++)
		P10[i] = P10[i - 1] * 10 % p;
	for (int i = 2; i <= 2 * n; i++)
		inv_P10[i] = inv_P10[i - 1] * inv_P10[1] % p;
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		x++, y++;
		add(x, y, w), add(y, x, w);
	}
	init_dfs(1, 0);
	dfs(1, 0);
	printf("%lld", ans);
	return 0;
}