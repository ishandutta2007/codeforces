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
#define maxn 1200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q, fa[maxn];
vector<int> G[maxn];
struct node
{
	int x, y, z;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.z < bb.z;
	}
}edge[maxn];
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int ans[maxn * 4], pos[maxn * 4], tag[maxn * 4], tmp[maxn * 4];
int dfn[maxn], val[maxn], tot, st[maxn][22], LOG[maxn];
void dfs(int x)
{
	dfn[x] = ++tot;
	if(x > n) val[tot] = edge[x - n].z;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		dfs(V);
		val[++tot] = edge[x - n].z;
	}
}
void init()
{
	LOG[1] = 0;
	for (int i = 2; i < maxn; i++) LOG[i] = LOG[i >> 1] + 1;
//	for (int i = 1; i <= tot; i++) printf("%d ", val[i]);
//	printf("\n");
	for (int i = tot; i >= 1; i--)
	{
		st[i][0] = val[i];
		for (int j = 1; j <= 20; j++)
		{
			if((i + (1 << j)) <= tot + 1) st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}
inline int query(int x, int y)
{
	if(x == 0 || y == 0 || x == y) return 0;
//	printf("%d %d ", x, y);
	x = dfn[x], y = dfn[y];
	if(x > y) swap(x, y);
	int len = LOG[y - x + 1];
//	printf("%d %d %d\n", x, y, max(st[x][len], st[y - (1 << len) + 1][len]));
	return max(st[x][len], st[y - (1 << len) + 1][len]);
}
void build(int x, int l, int r)
{
	tag[x] = -1;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lc(x), l, mid), build(rc(x), mid + 1, r);
	tmp[x] = max(tmp[lc(x)], tmp[rc(x)]);
	tmp[x] = max(tmp[x], query(l, r));
}
inline void pushdown(int x, int l, int r)
{
	if(tag[x] == 0)
	{
		tag[lc(x)] = tag[rc(x)] = 0;
		pos[lc(x)] = pos[rc(x)] = 0;
		ans[lc(x)] = ans[rc(x)] = 0;
	}
	if(tag[x] == 1)
	{
		tag[lc(x)] = tag[rc(x)] = 1;
		pos[lc(x)] = l, pos[rc(x)] = r;
		ans[lc(x)] = tmp[lc(x)], ans[rc(x)] = tmp[rc(x)];
	}
	tag[x] = -1;
}
inline void pushup(int x)
{
	ans[x] = max(ans[lc(x)], ans[rc(x)]);
	ans[x] = max(ans[x], query(pos[lc(x)], pos[rc(x)]));
	pos[x] = max(pos[lc(x)], pos[rc(x)]);
}
void modify(int tp, int x, int l, int r, int a, int b)
{
//	printf("%d %d %d %d %d %d\n", tp, x, l, r, a, b);
	if(a <= l && r <= b)
	{
		if(tp == 1) ans[x] = tmp[x], pos[x] = l, tag[x] = 1;
		if(tp == 0) ans[x] = pos[x] = tag[x] = 0;
		return;
	}
	pushdown(x, l, r);
	int mid = (l + r) >> 1;
	if(a <= mid) modify(tp, lc(x), l, mid, a, b);
	if(b > mid) modify(tp, rc(x), mid + 1, r, a, b);
	pushup(x);
//	printf("%d %d %d %d\n", l, r, ans[x], pos[x]);
}
int que(int x, int l, int r, int aim)
{
	if(l == r) return pos[x];
	pushdown(x, l, r);
	int mid = (l + r) >> 1;
	if(aim <= mid) return que(lc(x), l, mid, aim);
	else return que(rc(x), mid + 1, r, aim);
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= 2 * n; i++) fa[i] = i;
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read(), z = read();
		edge[i] = {x, y, z}; 
	} 
	sort(edge + 1, edge + n);
	for (int i = 1; i < n; i++)
	{
		edge[i].x = find(edge[i].x), edge[i].y = find(edge[i].y);
		G[n + i].push_back(edge[i].x);
		G[n + i].push_back(edge[i].y);
		fa[edge[i].x] = n + i, fa[edge[i].y] = n + i;
	}
	dfs(n + n - 1);
	init();
	build(1, 1, n);
	while(q--)
	{
		int tp = read();
		if(tp == 3)
		{
			int x = read();
			int tmp = que(1, 1, n, x);
			modify(1, 1, 1, n, x, x);
			if(ans[1] == 0) printf("-1\n");
			else printf("%d\n", ans[1]);
			if(!tmp) modify(0, 1, 1, n, x, x);
		}
		else 
		{
			int x = read(), y = read();
			modify(2 - tp, 1, 1, n, x, y);
		}
	}
	return 0;
}