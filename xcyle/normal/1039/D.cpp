#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
int n, dep[maxn], g[maxn], l[maxn], r[maxn], i;
int dfn[maxn], endd[maxn], tot, arr[maxn], anc[maxn][22];
vector<int> G[maxn], pos;
vector<int> id[maxn];
queue<int> q;
struct node
{
	int mx, mn, pre, suf, ans, tag;
	inline node friend operator + (node aa, node bb)
	{
		if(aa.tag == i) aa = {-n, n, -n, -n, -n, 0};
		if(bb.tag == i) bb = {-n, n, -n, -n, -n, 0};
		return {max(aa.mx, bb.mx), min(aa.mn, bb.mn), max(max(aa.pre, bb.pre), aa.mx - 2 * bb.mn), max(max(aa.suf, bb.suf), -2 * aa.mn + bb.mx), max(max(aa.ans, bb.ans), max(aa.pre + bb.mx, aa.mx + bb.suf))};
	}
}t[maxn * 4], epy;
int tt[maxn];
inline void add(int x, int d)
{
	for (; x <= tot; x += x & -x) tt[x] += d;
}
inline int que(int x)
{
	int res = 0;
	for (; x; x -= x & -x) res += tt[x];
	return res; 
}
void dfs(int x, int fa)
{
	anc[x][0] = fa;
	for (int i = 1; i <= 17; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	dep[x] = dep[fa] + 1;
	arr[++tot] = x;
	dfn[x] = tot;
	g[x] = 1;
	int mx1 = 0, mx2 = 0;
	for (auto V: G[x])
	{
		if(V == fa) continue;
		dfs(V, x);
		if(g[V] > mx1) mx2 = mx1, mx1 = g[V];
		else mx2 = max(mx2, g[V]);
		g[x] = max(g[x], g[V] + 1);
		l[x] = max(l[x], r[V] + 1);
		arr[++tot] = x;
	}
	r[x] = max(l[x] - 1, mx1 + mx2 + 1);
	for (int i = l[x]; i <= r[x]; i++) id[i].push_back(x);
	endd[x] = tot;
}
void build(int x, int l, int r)
{
	if(l == r)
	{
		t[x] = {dep[arr[l]], dep[arr[l]], -dep[arr[l]], -dep[arr[l]], 0};
		return;
	}
	int mid = (l + r) >> 1;
	build(lc(x), l, mid), build(rc(x), mid + 1, r);
	t[x] = t[lc(x)] + t[rc(x)];
}
inline void modify(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b)
	{
		t[x].tag = i;
		return;
	}
	int mid = (l + r) >> 1;
	if(a <= mid) modify(lc(x), l, mid, a, b);
	if(b > mid) modify(rc(x), mid + 1, r, a, b);
	t[x] = t[lc(x)] + t[rc(x)];
}
inline void rebuild(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return;
	int mid = (l + r) >> 1;
	if(a <= mid) rebuild(lc(x), l, mid, a, b);
	if(b > mid) rebuild(rc(x), mid + 1, r, a, b);
	t[x] = t[lc(x)] + t[rc(x)];
}
inline node query(int x, int l, int r, int a, int b)
{
	if(t[x].tag == i) return epy;
	if(a <= l && r <= b) return t[x];
	int mid = (l + r) >> 1;
	if(a <= mid && b > mid) return query(lc(x), l, mid, a, b) + query(rc(x), mid + 1, r, a, b);
	if(a <= mid) return query(lc(x), l, mid, a, b);
	if(b > mid) return query(rc(x), mid + 1, r, a, b);
}
inline void write(int x)
{
	if(x >= 10) write(x / 10);
	putchar('0' + x % 10);
}
int main()
{
//	freopen("data.in", "r", stdin);
	n = read();
	epy = {-n, n, -n, -n, -n};
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 1);
	i = 1;
	build(1, 1, tot);
//	for (int i = 1; i <= n; i++)
//	{
//		for (auto x: id[i]) printf("%d ", x);
//		printf("\n");
//	}
//	printf("%d %d %d %d %d\n", t[1].mx, t[1].mn, t[1].pre, t[1].suf, t[1].ans);
	for (i = 1; i <= n; i++)
	{
		for (auto x: pos) rebuild(1, 1, tot, dfn[x], endd[x]);
		pos.clear();
		int res = 0;
		for (auto x: id[i]) q.push(x), add(dfn[x], 1);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			res++;
			pos.push_back(x);
			modify(1, 1, tot, dfn[x], endd[x]);
			add(dfn[x], -1);
//			printf("1::: %d\n", query(1, 1, tot, 1, tot).ans + 1);
			if(t[1].ans + 1 < i) continue;
			for (int j = 17; j >= 0; j--)
			{
			    if((1 << j) > i) continue;
				if(query(1, 1, tot, dfn[anc[x][j]], endd[anc[x][j]]).ans + 1 >= i) continue;
				x = anc[x][j];
			}
//			printf("!%d\n", x);
			if(x == 1) continue;
			x = anc[x][0];
//			printf("!%d %d\n", x, que(endd[x]) - que(dfn[x] - 1));
			if(que(endd[x]) == que(dfn[x] - 1)) add(dfn[x], 1), q.push(x);
		}
		write(res);
		putchar('\n');
	}
	return 0;
}