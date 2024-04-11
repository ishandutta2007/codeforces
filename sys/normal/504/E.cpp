#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 300005, p = 1e9 + 9, seed = 29;
int n, q, ans, ct, cnt, inv_seed, head[Maxn], siz[Maxn], dfn[Maxn], bel[Maxn], bot[Maxn], son[Maxn], top[Maxn], fa[Maxn], dep[Maxn];
long long Hash1[Maxn], Hash2[Maxn], Pow[Maxn], inv[Maxn];
string str;
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
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
void dfs1(int u, int f)
{
	siz[u] = 1;
	dep[u] = dep[f] + 1;
	fa[u] = f;
	Hash1[u] = (Hash1[f] * seed + str[u - 1] - 'a') % p;
	Hash2[u] = (Hash2[f] + (str[u - 1] - 'a') * Pow[dep[u]] % p) % p;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != f)
		{
			dfs1(to, u);
			siz[u] += siz[to];
			if (siz[to] > siz[son[u]]) son[u] = to;
		}
	} 
}
void dfs2(int u, int tp)
{
	bot[u] = u;
	dfn[u] = ++ct;
	bel[ct] = u;
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp), bot[u] = bot[son[u]];
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa[u] && to != son[u])
			dfs2(to, to), bot[to] = bot[son[to]];
	}
}
int lca(int x, int y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] > dep[y] ? y : x;
}
int get_hash(int pos, int range, int type)
{
	if (type)
	{
		int pos2 = bel[dfn[pos] + range - 1];
		return (Hash1[pos2] - Hash1[fa[pos]] * Pow[range] % p + p) % p;
	}
	else
	{
		int pos2 = bel[dfn[pos] - range + 1];
		return (Hash2[pos] - Hash2[fa[pos2]] + p) * inv[dep[fa[pos2]] + 1] % p;
	}
}
vector <int> Ve1, Ve2;
int work(int a1, int b1, int a2, int b2)
{
	Ve1.clear(), Ve2.clear();
	ans = 0;
	int lca1 = lca(a1, b1), lca2 = lca(a2, b2);
	int tmpb1 = b1, tmpb2 = b2;
	while (top[tmpb1] != top[lca1]) Ve1.push_back(top[tmpb1]), tmpb1 = fa[top[tmpb1]];
	while (top[tmpb2] != top[lca2]) Ve2.push_back(top[tmpb2]), tmpb2 = fa[top[tmpb2]];
	reverse(Ve1.begin(), Ve1.end());
	reverse(Ve2.begin(), Ve2.end());
	Ve1.push_back(n + 1);
	Ve2.push_back(n + 1);
	int pnt1 = 0, pnt2 = 0;
	bool type1 = false, type2 = false;
	if (a1 == lca1) type1 = true;
	if (a2 == lca2) type2 = true;
	while (true)
	{
		int now = 0x3f3f3f3f;
		if (type1) now = min(now, min(dep[b1] - dep[a1], dep[Ve1[pnt1]] - 1 - dep[a1]));
		else now = min(now, min(dep[a1] - dep[lca1], dep[a1] - dep[top[a1]]));
		if (type2) now = min(now, min(dep[b2] - dep[a2], dep[Ve2[pnt2]] - 1 - dep[a2]));
		else now = min(now, min(dep[a2] - dep[lca2], dep[a2] - dep[top[a2]]));
		now++;
		if (get_hash(a1, now, type1) == get_hash(a2, now, type2))
		{
			ans += now;
			if ((type1 && bel[dfn[a1] + now - 1] == b1) || (!type1 && bel[dfn[a1] - now + 1] == b1) || (type2 && bel[dfn[a2] + now - 1] == b2) || (!type2 && bel[dfn[a2] - now + 1] == b2)) return ans;
			if (type1)
			{
				if (bel[dfn[a1] + now - 1] != fa[Ve1[pnt1]]) a1 = bel[dfn[a1] + now];
				else a1 = Ve1[pnt1++];
			}
			else
			{
				if (bel[dfn[a1] - now + 1] == lca1)
				{
					type1 = true;
					if (fa[Ve1[0]] == lca1) a1 = Ve1[pnt1++];
					else a1 = son[lca1];
				}
				else a1 = fa[bel[dfn[a1] - now + 1]];
			}
			if (type2)
			{
				if (bel[dfn[a2] + now - 1] != fa[Ve2[pnt2]]) a2 = bel[dfn[a2] + now];
				else a2 = Ve2[pnt2++];
			}
			else 
			{
				if (bel[dfn[a2] - now + 1] == lca2)
				{
					type2 = true;
					if (fa[Ve2[0]] == lca2) a2 = Ve2[pnt2++];
					else a2 = son[lca2];
				}
				else a2 = fa[bel[dfn[a2] - now + 1]];
			}
		}
		else
		{
			int l = 0, r = now - 1;
			while (l + 1 <= r)
			{
				int mid = (l + r + 1) >> 1;
				if (get_hash(a1, mid, type1) == get_hash(a2, mid, type2))
					l = mid;
				else r = mid - 1;
			}
			return ans + l;
		}
		if (a1 == lca1) type1 = true;
		if (a2 == lca2) type2 = true;
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	dep[n + 1] = 0x3f3f3f3f;
	inv_seed = fast_pow(seed, p - 2);
	Pow[0] = 1, inv[0] = 1;
	for (int i = 1; i <= n; i++)
		Pow[i] = Pow[i - 1] * seed % p, inv[i] = inv[i - 1] * inv_seed % p;
	cin >> str;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", work(a, b, c, d));
	}
	return 0;
}