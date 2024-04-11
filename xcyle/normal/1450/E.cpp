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
#define maxn 205
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, gap, ans[maxn];
vector<pii> G[maxn];
int dis[maxn], vis[maxn], cnt[maxn];
queue<int> q;
void spfa()
{
	ru(s, 1, n)
	{ 
		ru(i, 1, n) dis[i] = INF, vis[i] = 0, cnt[i] = 0;
		dis[s] = 0, vis[s] = 1, q.push(s);
		while(!q.empty())
		{
			int x = q.front(); q.pop(); vis[x] = 0;
			for (auto t: G[x])
			{
				int V = t.fi, W = t.se;
				if(dis[V] > dis[x] + W)
				{
					dis[V] = dis[x] + W;
					if(!vis[V]) 
					{
						q.push(V), vis[V] = 1, cnt[V]++;
						if(cnt[V] >= n) {printf("NO\n"); exit(0);}
					}
				}
			}
		}
		int mn = INF, mx = -INF;
		ru(i, 1, n) mn = min(mn, dis[i]), mx = max(mx, dis[i]);
		ru(i, 1, n) dis[i] -= mn;
		if(mx - mn >= gap)
		{
			gap = mx - mn;
			ru(i, 1, n) ans[i] = dis[i];
		}
	}
}
int main()
{
	n = read(), m = read();
	ru(i, 1, m)
	{
		int x = read(), y = read(), tp = read();
		G[x].push_back(mp(y, 1));
		G[y].push_back(mp(x, 1 - 2 * tp));
	}
	spfa();
	ru(x, 1, n)
	{
		for (auto t: G[x])
		{
			int V = t.fi, W = t.se;
			if(dis[V] > dis[x] + W || dis[V] == dis[x]) {printf("NO\n"); return 0;}
		}
	}
	printf("YES\n%d\n", gap);
	ru(i, 1, n) printf("%d ", ans[i]);
	return 0;
}