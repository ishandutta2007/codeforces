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
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
const int INF = 1e9 + 1;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, q, tmp, w[maxn];
int dfn[maxn], low[maxn], sta[maxn], Top, tot, cnt;
vector<int> G[maxn], T[maxn];
inline void tarjan(int x)
{
	dfn[x] = low[x] = ++tot, sta[++Top] = x;
	for (auto V: G[x])
	{
		if(!dfn[V])
		{
			tarjan(V);
			low[x] = min(low[x], low[V]);
			if(low[V] >= dfn[x])
			{
				w[++cnt] = INF;
				while(sta[Top] != V) T[cnt].push_back(sta[Top]), T[sta[Top--]].push_back(cnt);
				Top--;
				T[cnt].push_back(V), T[V].push_back(cnt);
				T[cnt].push_back(x), T[x].push_back(cnt);
			}
		}
		else low[x] = min(low[x], dfn[V]);
	}
}
int dfn2[maxn], maxson[maxn], siz[maxn], top[maxn], fat[maxn], dep[maxn], arr[maxn];
void dfs1(int x, int fa)
{
	siz[x] = 1, dep[x] = dep[fat[x] = fa] + 1;
	for (auto V: T[x]) if(V ^ fa)
	{
		dfs1(V, x);
		siz[x] += siz[V];
		if(siz[V] > siz[maxson[x]]) maxson[x] = V;
	}
}
void dfs2(int x, int anc)
{
	top[x] = anc, arr[dfn2[x] = ++tot] = x;
	if(maxson[x]) dfs2(maxson[x], anc);
	for (auto V: T[x]) if(V != maxson[x] && V != fat[x]) dfs2(V, V);
}
multiset<int> son[maxn];
int t[maxn * 4];
char tp[3];
inline void modify(int x, int l, int r, int pos)
{
	if(l == r) {t[x] = w[arr[pos]]; return;}
	if(pos <= mid) modify(lc(x), l, mid, pos);
	else modify(rc(x), mid + 1, r, pos);
	t[x] = min(t[lc(x)], t[rc(x)]);
}
inline int que(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return t[x];
	int res = INF;
	if(a <= mid) res = min(res, que(lc(x), l, mid, a, b));
	if(b > mid) res = min(res, que(rc(x), mid + 1, r, a, b));
	return res;
}
inline int query(int x, int y)
{
	int res = INF;
	while(top[x] != top[y])
	{
		if(dep[top[x]] > dep[top[y]]) swap(x, y);
		res = min(res, que(1, 1, n, dfn2[top[y]], dfn2[y]));
		y = fat[top[y]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	res = min(res, que(1, 1, n, dfn2[x], dfn2[y]));
//	printf("!%d\n", fat[x]);
	if(x > tmp) res = min(res, w[fat[x]]);
	return res;
}
int main()
{
	cnt = n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1; i <= m; i++) {int x = read(), y = read(); G[x].push_back(y), G[y].push_back(x);}
	for (int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	tot = 0, dfs1(1, 0), dfs2(1, 1);
	tmp = n; n = cnt;
	for (int i = 1; i <= 4 * n; i++) t[i] = INF;
	for (int i = 1; i <= tmp; i++)
	{
		son[fat[i]].insert(w[i]);
		w[fat[i]] = *(son[fat[i]].begin());
		modify(1, 1, n, dfn2[fat[i]]), modify(1, 1, n, dfn2[i]);
	}
	while(q--)
	{
		scanf("%s", tp); int a = read(), b = read();
		if(tp[0] == 'C')
		{
			son[fat[a]].erase(son[fat[a]].find(w[a]));
			son[fat[a]].insert(w[a] = b);
			w[fat[a]] = *(son[fat[a]].begin());
			modify(1, 1, n, dfn2[fat[a]]), modify(1, 1, n, dfn2[a]);
		}
		else printf("%d\n", query(a, b));
	}
	return 0;
}