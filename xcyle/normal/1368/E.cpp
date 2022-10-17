/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
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
int T, d[maxn], f[maxn], vis[maxn];
vector<int> G[maxn];
queue<int> q;
void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) d[i] = 0;
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		d[y]++;
	}
	for (int i = 1; i <= n; i++) vis[i] = f[i] = 0;
	for (int i = 1; i <= n; i++) if(!d[i]) q.push(i);
	int cnt = 0;
	while(!q.empty())
	{
		int u = q.front();
		if(f[u] == 2)
		{
			vis[u] = 1;
			cnt++;
		}
		q.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int V = G[u][i];
			d[V]--;
			if(!vis[u]) f[V] = max(f[V], f[u] + 1);
			if(!d[V]) q.push(V);
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) if(vis[i]) printf("%d ", i);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}