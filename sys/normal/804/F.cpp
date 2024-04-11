#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 5005, p = 1e9 + 7;
int n, m, a, b, cnt, top, scc, dfn_cnt, ord_ct, siz[Maxn], ord[Maxn], bel[Maxn], g[Maxn], val[Maxn], deg[Maxn], dfn[Maxn], low[Maxn], sta[Maxn], mini[Maxn], maxi[Maxn];
bool in_stack[Maxn];
long long ans, fac[Maxn], inv[Maxn];
vector <int> G[Maxn], R[Maxn];
basic_string <bool> Ve[Maxn];
string str[Maxn];
long long get_inv(int x)
{
	return x <= 1 ? 1 : (p - p / x) * get_inv(p % x) % p;
}
void Tarjan(int u)
{
	dfn[u] = low[u] = ++dfn_cnt;
	sta[++top] = u;
	in_stack[u] = true;
	for (auto to : R[u])
	{
		if (!dfn[to])
		{
			Tarjan(to);
			low[u] = min(low[u], low[to]);
		}
		else if (in_stack[to]) low[u] = min(low[u], dfn[to]);
	}
	if (low[u] == dfn[u])
	{
		scc++;
		int x;
		do
		{
			x = sta[top--];
			in_stack[x] = false;
			bel[x] = scc;
			g[scc] = __gcd(g[scc], val[x]);
		}
		while (x != u);
	}
}
void rebuild(void)
{
	for (int u = 1; u <= n; u++)
		for (auto to : R[u])
			if (bel[u] != bel[to]) G[bel[u]].push_back(bel[to]);
}
queue <int> Qu;
void bfs(bool type = false)
{
	ord_ct = 0;
	for (int i = 1; i <= n; i++)
		for (auto to : G[i]) deg[to]++;
	for (int i = 1; i <= scc; i++)
		if (!deg[i]) Qu.push(i);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		ord[++ord_ct] = u;
		for (auto to : G[u])
		{
			deg[to]--;
			g[to] = __gcd(g[to], g[u]);
			if (!deg[to]) Qu.push(to);
		}
	}
	for (int i = 1; i < ord_ct; i++)
		for (int j = 0; j < g[ord[i]]; j++)
			Ve[ord[i + 1]][j % g[ord[i + 1]]] |= Ve[ord[i]][j];
	for (int i = 1; i <= scc; i++)
		for (auto e : Ve[i])
			siz[i] += e;
}
long long C(int x, int y)
{
	if (x < y || x < 0 || y < 0) return 0;
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p, inv[i] = get_inv(fac[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			char ch = getchar();
			while (ch != '0' && ch != '1') ch = getchar();
			if (ch == '1') R[i].push_back(j);
		}
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i] >> str[i];
		for (int j = 0; j < val[i]; j++)
			mini[i] += (str[i][j] == '1');
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) Tarjan(i);
	rebuild();
	for (int i = 1; i <= scc; i++)
		Ve[i].resize(g[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < val[i]; j++)
			if (str[i][j] == '1')
				Ve[bel[i]][j % g[bel[i]]] = true;
	bfs();
	for (int i = 1; i <= n; i++)
		maxi[i] = val[i] / g[bel[i]] * siz[bel[i]];
	for (int i = 1; i <= n; i++)
	{
		int ct1 = 0, ct2 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (mini[j] > maxi[i]) ct1++;
			else if (maxi[j] > maxi[i] || (maxi[i] == maxi[j] && i > j)) ct2++;
		}
		if (ct1 > a - 1) continue;
		for (int j = min(b - 1, min(a - 1 - ct1, ct2)); ct1 >= b - j - 1; j--)
			(ans += C(ct2, j) * C(ct1, b - j - 1)) %= p;
	}
	printf("%lld", ans);
	return 0;
}