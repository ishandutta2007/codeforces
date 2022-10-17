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
int n, m;
vector<int> G[maxn], val[maxn], G2[maxn], val2[maxn];
int dep[maxn], fl = 1, vis[maxn];
void dfs(int x)
{
//	printf("%d %d\n", x, dep[x]);
	vis[x] = 1;
	for (int i = 0; i < G2[x].size(); i++)
	{
		int V = G2[x][i], nxt = (dep[x] ^ val2[x][i]);
		if(vis[V])
		{
			if(nxt != dep[V]) fl = 0;
//			if(nxt != dep[V]) printf("%d %d %d %d\n", x, V, dep[x], dep[V]);
			continue;
		}
		dep[V] = nxt;
		dfs(V);
	}
}
void solve()
{
	fl = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) G[i].clear(), val[i].clear(), G2[i].clear(), val2[i].clear(); 
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read(), w = read();
		G[u].push_back(v);
		G[v].push_back(u); 
		val[u].push_back(w);
		val[v].push_back(w);
		if(w != -1)
		{
			int cnt = 0;
			for (int j = 0; j <= 30; j++) cnt += ((w >> j) & 1);
			w = (cnt & 1);
			G2[u].push_back(v);
			G2[v].push_back(u);
			val2[u].push_back(w);
			val2[v].push_back(w);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u = read(), v = read(), w = read();
		G2[u].push_back(v);
		G2[v].push_back(u);
		val2[u].push_back(w);
		val2[v].push_back(w);
	}
	for (int i = 1; i <= n; i++) vis[i] = 0, dep[i] = 0;
	for (int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
	if(!fl)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			int V = G[i][j];
			if(V < i) continue;
			if(val[i][j] == -1) val[i][j] = (dep[i] ^ dep[V]);
			printf("%d %d %d\n", i, V, val[i][j]);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}