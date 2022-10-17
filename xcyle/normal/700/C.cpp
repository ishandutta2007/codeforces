/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, s, t, vis[maxn], dfn[maxn], low[maxn], tot = 0, cnt, bel[maxn];
int W[maxn];
struct edge {int v, w, id;};
vector<edge> G[maxn], T[maxn];
int sta[maxn], top, sta2[maxn], top2, fl;
void dfs(int x)
{
	vis[x] = 1; if(x == t) {fl = 1; return;}
	for (auto i: G[x]) if(!vis[i.v])
	{
		sta[++top] = i.id;
		dfs(i.v);
		if(fl) return;
		top--;
	}
}
void dfs2(int x)
{
	vis[x] = 1; if(x == bel[t]) {fl = 1; return;}
	for (auto i: T[x]) if(!vis[i.v])
	{
		sta2[++top2] = i.id;
		dfs2(i.v);
		if(fl) return;
		top2--;
	}
}
int ans = 2e9 + 1, a, b;
int ban;
void tar(int x, int ID)
{
	dfn[x] = low[x] = ++tot;
	sta2[++top2] = x;
	for (auto i: G[x]) if(i.id != ban && i.id != ID)
	{
		int V = i.v;
		if(!dfn[V]) tar(V, i.id), low[x] = min(low[x], low[V]);
		else low[x] = min(low[x], dfn[V]);
	}
//	printf("%d %d %d\n", x, low[x], dfn[x]);
	if(dfn[x] == low[x])
	{
//		printf("??? %d\n", x);
		cnt++;
		while(sta2[top2] != x) bel[sta2[top2--]] = cnt;
		bel[sta2[top2--]] = cnt;
	}
}
int main()
{
	n = read(), m = read(), s = read(), t = read();
	ru(i, 1, m) 
	{
		int x = read(), y = read(), w = read(); W[i] = w;
		G[x].push_back((edge){y, w, i});
		G[y].push_back((edge){x, w, i});
	}
	dfs(s);
	if(!fl) {printf("0\n0"); return 0;}
	ru(i, 1, top)
	{
		ban = sta[i];
		ru(j, 1, n) dfn[j] = low[j] = bel[j] = 0; cnt = tot = 0;
		top2 = 0; tar(s, 0);
		if(bel[s] == bel[t]) continue;
		if(!dfn[t])
		{
			if(ans > W[ban]) ans = W[ban], a = ban, b = 0;
			continue;
		}
		ru(j, 1, n) T[j].clear(), vis[j] = 0; top2 = 0;
//		ru(j, 1, n) printf("%d ", bel[j]); printf("\n");
		ru(j, 1, n) for (auto V: G[j]) if(V.id != ban && bel[j] != bel[V.v])
		{
			T[bel[j]].push_back({bel[V.v], V.w, V.id});
		}
		fl = 0; dfs2(bel[s]);
		ru(j, 1, top2) 
		{
			if(ans > W[sta[i]] + W[sta2[j]]) ans = W[sta[i]] + W[sta2[j]], a = sta[i], b = sta2[j];
		}
	}
	if(!a) {printf("-1\n"); return 0;}
	printf("%d\n", ans);
	if(!b) printf("1\n%d\n", a);
	else printf("2\n%d %d\n", a, b);
	return 0;
}