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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, h, a[maxn];
vector<int> G[maxn];
int dfn[maxn], tot, low[maxn];
int bel[maxn], cnt, val[maxn], d[maxn];
int sta[maxn], top, vis[maxn], typ[maxn];
int ans = 0; 
queue<int> q;
void tar(int x)
{
	sta[++top] = x;
	dfn[x] = low[x] = ++tot;
	vis[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(!dfn[V])
		{
			tar(V);
			low[x] = min(low[x], low[V]);
		}
		else if(vis[V]) low[x] = min(low[x], dfn[V]);
	}
	if(low[x] == dfn[x])
	{
		cnt++;
		for (; sta[top] != x; top--)
		{
			bel[sta[top]] = cnt;
			vis[sta[top]] = 0;
			val[cnt]++;
		}
		val[cnt]++;
		top--;
		bel[x] = cnt;
//		printf("%d %d %d\n", cnt, x, bel[x]);
		vis[x] = 0;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(a[u] == (a[v] + 1) % h) G[v].push_back(u);
		if(a[v] == (a[u] + 1) % h) G[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!dfn[i]) tar(i);
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto V: G[i])
		{
			if(bel[V] != bel[i]) typ[bel[i]] = 1;
		}
	}
	ans = -1;
	for (int i = 1; i <= cnt; i++)
	{
		if(!typ[i])
		{
			if(ans == -1) ans = i;
			else if(val[i] < val[ans]) ans = i;
		}
	}
	printf("%d\n", val[ans]);
//	for (int i = 1; i <= n; i++) printf("%d ", bel[i]);
//	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) if(bel[i] == ans) printf("%d ", i);
	return 0;
}