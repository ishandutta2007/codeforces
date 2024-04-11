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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
vector<int> G[maxn];
int dep[maxn], dfn[maxn], siz[maxn], tot, vis[maxn];
int t[maxn * 4], pos[maxn * 4], tag[maxn * 4], fat[maxn], rk[maxn];
void dfs(int x, int fa)
{
	fat[x] = fa;
	dep[x] = dep[fa] + 1;
	dfn[x] = ++tot;
	rk[tot] = x;
	siz[x] = 1;
	for (auto V: G[x])
	{
		if(V == fa) continue;
		dfs(V, x), siz[x] += siz[V];
	} 
}
inline void pushup(int x)
{
	t[x] = max(t[lc(x)], t[rc(x)]);
	if(t[lc(x)] > t[rc(x)]) pos[x] = pos[lc(x)];
	else pos[x] = pos[rc(x)];
}
inline void pushdown(int x)
{
	if(!tag[x]) return;
	tag[lc(x)] += tag[x];
	t[lc(x)] += tag[x];
	tag[rc(x)] += tag[x];
	t[rc(x)] += tag[x];
	tag[x] = 0;
}
void build(int x, int l, int r)
{
	if(l == r)
	{
		pos[x] = rk[l];
		t[x] = dep[rk[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc(x), l, mid);
	build(rc(x), mid + 1, r);
	pushup(x);
//	printf("%d %d %d %d %d\n", x, l, r, t[x], pos[x]);
}
void add(int x, int l, int r, int a, int b, int d)
{
	if(a <= l && r <= b)
	{
		t[x] += d;
		tag[x] += d;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) add(lc(x), l, mid, a, b, d);
	if(b > mid) add(rc(x), mid + 1, r, a, b, d);
	pushup(x);
}
void work(int x)
{
	if(vis[x] || !x) return;
	vis[x] = 1;
	add(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, -1);
	work(fat[x]);
}
int main()
{
//	freopen("data.in", "r", stdin);
	int k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	build(1, 1, n);
	ll ans = -(ll)n * n;
	int num = 0;
	for (int i = 1; i <= k; i++)
	{
//		printf("%d\n", dep[1]);
		int now = pos[1];
		num += t[1];
		ll tmp = min(n / 2, n - num);
		work(now);
//		printf("%d %d\n", now, num);
		ans = max(ans, (ll)(n - tmp - i) * (i - tmp));
	}
	printf("%lld", ans);
	return 0;
}