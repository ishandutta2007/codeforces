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
#define maxn 1000005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m;
int dis[maxn], cnt[maxn], d[maxn], vis[maxn];
vector<int> G[maxn], Gf[maxn];
struct node
{
	int dd, id;
	inline bool friend operator < (node aa, node bb)
	{
		return aa.dd > bb.dd;
	}
};
priority_queue<node> q;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		d[u]++;
		Gf[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) dis[i] = INF;
	int s, t;
	scanf("%d%d", &s, &t);
	dis[t] = 0;
	cnt[t] = d[t];
	q.push({0, t});
	while(!q.empty())
	{
		int u = q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		dis[u] += (cnt[u] != d[u]);
		for (int i = 0; i < Gf[u].size(); i++)
		{
			int V = Gf[u][i];
			if(vis[V]) continue;
			if(dis[V] == dis[u])
			{
				cnt[V]++;
				q.push({dis[V] + (cnt[V] != d[V]), V});
			}
			if(dis[V] > dis[u])
			{
				dis[V] = dis[u];
				cnt[V] = 1;
				q.push({dis[V] + (cnt[V] != d[V]), V});
			}
		}
	}
	if(dis[s] == INF) printf("-1\n");
	else printf("%d\n", dis[s]);
	return 0;
}