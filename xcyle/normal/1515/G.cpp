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
#define int long long
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
vector<int> G[maxn], val[maxn];
vector<int> p[maxn];
int dfn[maxn], low[maxn], bel[maxn], tot, sta[maxn], top, vis[maxn], cnt;
void tarjan(int x)
{
	dfn[x] = low[x] = ++tot;
	sta[++top] = x;
	vis[x] = 1;
	for (auto V: G[x])
	{
		if(!dfn[V])
		{
			tarjan(V);
			low[x] = min(low[x], low[V]); 
		}
		else if(vis[V]) low[x] = min(low[x], dfn[V]);
	}
	if(dfn[x] == low[x])
	{
		cnt++;
		for (; sta[top] != x; top--)
		{
			bel[sta[top]] = cnt;
			vis[sta[top]] = 0;
			p[cnt].push_back(sta[top]); 
		}
		bel[x] = cnt, vis[x] = 0, p[cnt].push_back(x);
		top--;
	} 
}
int dep[maxn], d[maxn], fa[maxn];
void dfs(int x)
{
	vis[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(bel[V] != bel[x] || vis[V]) continue;
		dep[V] = dep[x] + val[x][i];
		fa[V] = x;
		dfs(V);
	}
}
inline int gcd(int x, int y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read(), z = read();
		G[x].push_back(y);
		val[x].push_back(z);
	}
	for (int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	for (int i = 1; i <= cnt; i++)
	{
		for (auto x: p[i]) vis[x] = 0;
		dfs(p[i][0]);
		for (auto x: p[i])
		{
			for (int j = 0; j < G[x].size(); j++)
			{
				if(fa[G[x][j]] == x || bel[G[x][j]] != i) continue;
				int tmp = val[x][j] - dep[G[x][j]] + dep[x];
				if(tmp < 0) tmp = -tmp;
				d[i] = gcd(d[i], tmp);
			}
		}
	}
	int q = read();
	while(q--)
	{
		int x = read(), s = read(), t = read();
		t = gcd(t, d[bel[x]]);
		if(s % t == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}