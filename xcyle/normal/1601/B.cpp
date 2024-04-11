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
int n, a[maxn], b[maxn];
int t[maxn * 4], dis[maxn];
int tot, ch[maxn][2], fa[maxn];
vector<int> G[maxn], Gf[maxn], val[maxn], valf[maxn];
vector<int> ans;
void add(int x, int y, int z)
{
	G[x].push_back(y);
	val[x].push_back(z);
	Gf[y].push_back(x);
	valf[y].push_back(z);
}
int build(int l, int r)
{
	if(l == r) return l;
	int now = ++tot;
	int mid = (l + r) >> 1;
	ch[now][0] = build(l, mid);
	ch[now][1] = build(mid + 1, r);
	add(now, ch[now][0], 0);
	add(now, ch[now][1], 0);
	fa[ch[now][0]] = fa[ch[now][1]] = now;
	return now;
}
void addt(int x, int l, int r, int a, int b, int to)
{
	if(a <= l && r <= b)
	{
		add(to, x, 1);
		return;
	}
	int mid = (l + r) >> 1;
	if(a <= mid) addt(ch[x][0], l, mid, a, b, to);
	if(b > mid) addt(ch[x][1], mid + 1, r, a, b, to); 
}
queue<int> q[2];
int vis[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	tot = 2 * n;
	int tmp = build(0, n);
	for (int i = 1; i <= n; i++)
	{
		add(i, n + i + b[i], 1);
		addt(tmp, 0, n, i - a[i], i, n + i);
	}
	for (int i = 0; i <= tot; i++) dis[i] = INF;
	dis[2 * n] = 0;
	q[0].push(2 * n);
	while(!q[0].empty() || !q[1].empty())
	{
		int u;
		if(q[0].empty()) u = 1;
		else if(q[1].empty()) u = 0;
		else u = (dis[q[0].front()] < dis[q[1].front()]) ? 0 : 1;
		int tmp = u;
		u = q[tmp].front();
		q[tmp].pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < G[u].size(); i++)
		{
			int V = G[u][i];
			if(dis[V] > dis[u] + val[u][i])
			{
				dis[V] = dis[u] + val[u][i];
				q[val[u][i]].push(V);
			}
		}
	}
	if(dis[0] == INF)
	{
		printf("-1");
		return 0;
	}
	int now = 0;
	while(now != 2 * n)
	{
		if(now <= n) ans.push_back(now);
		for (int i = 0; i < Gf[now].size(); i++)
		{
			int V = Gf[now][i];
			if(dis[V] == dis[now] - valf[now][i])
			{
				now = V;
				break;
			}
		}
	}
	printf("%d\n", ans.size());
	for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
	return 0;
}