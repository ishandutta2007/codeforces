/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxa 10000005
#define maxn 100005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], vis2[maxa];
vector<int> G[maxn], hav[maxa];
int vis[maxa], prime[maxa], tot;
int fa[maxn][22], dep[maxn];
void dfs1(int x)
{
	for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (auto V: G[x])
	{
		if(V == fa[x][0]) continue;
		dep[V] = dep[x] + 1, fa[V][0] = x;
		dfs1(V);
	}
}
int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) if(dep[fa[y][i]] >= dep[x]) y = fa[y][i];
	if(x == y) return x;
	for (int i = 20; i >= 0; i--) if(fa[x][i] != fa[y][i]) {x = fa[x][i], y = fa[y][i];}
	return fa[x][0];
}
struct node
{
	int id, tp, w;
};
vector<node> que[maxn];
int ans[maxn], id[maxa];
int cnt[700005][30], suf[700005][30];
inline int poww(int x, ll step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
void dfs2(int x, int fa)
{
	for (auto p: hav[a[x]])
	{
		int num = 0;
		for (int i = a[x]; i % p == 0; i /= p) suf[id[p]][++num]++;
		cnt[id[p]][num]++;
	}
	for (auto o: que[x])
	{
		int res = 1;
		for (auto p: hav[o.w])
		{
			int num = 0;
			for (int i = o.w; i % p == 0; i /= p, num++)
			{
				res = (ll)res * poww(p, (ll)(num + 1) * cnt[id[p]][num + 1]) % mo;
			}
			res = (ll)res * poww(p, (ll)num * suf[id[p]][num + 1] % mo) % mo;
		}
		if(o.tp == -1) res = poww(res, mo - 2) % mo;
		ans[o.id] = (ll)ans[o.id] * res % mo;
	}
	for (auto V: G[x])
	{
		if(V == fa) continue;
		dfs2(V, x);
	}
	for (auto p: hav[a[x]])
	{
		int num = 0;
		for (int i = a[x]; i % p == 0; i /= p) suf[id[p]][++num]--;
		cnt[id[p]][num]--;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) vis2[a[i] = read()] = 1;
	dep[1] = 1, dfs1(1);
	int q = read();
	for (int i = 1; i <= q; i++)
	{
		int u = read(), v = read(), w = read();
		int x = lca(u, v);
		que[v].push_back({i, 1, w}), que[u].push_back({i, 1, w});
		que[fa[x][0]].push_back({i, -1, w}), que[x].push_back({i, -1, w});
		ans[i] = 1;
		vis2[w] = 1;
	}
	for (int i = 2; i < maxa; i++)
	{
		if(!vis[i])
		{
			prime[++tot] = i, id[i] = tot;
			for (int j = i; j < maxa; j += i) if(vis2[j]) hav[j].push_back(i);
		}
		for (int j = 1; j <= tot && i * prime[j] < maxa; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	dfs2(1, 1);
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}