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
const ll INF = 9e17;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll h[maxn];
vector<int> G[maxn];
ll f[maxn], mx[maxn], g[maxn];
int rt;
void dfs(int x, int fa)
{
	if(G[x].size() == 1 && x != rt)
	{
		f[x] = mx[x] = h[x];
		return;
	}
	for (auto V: G[x])
	{
		if(V == fa) continue;
		dfs(V, x);
		f[x] += f[V];
		mx[x] = max(mx[x], mx[V]);
	}
	if(h[x] > mx[x]) 
	{
		f[x] += h[x] - mx[x];
		mx[x] = h[x];
	}
//	printf("%d %lld\n", x, f[x]);
}
void dfs2(int x, int fa)
{
	g[x] = INF;
	if(G[x].size() == 1) g[x] = 0;
	ll sum = 0;
	for (auto V: G[x]) 
	{
		if(V == fa) continue;
		dfs2(V, x), sum += f[V];
	}
	for (auto V: G[x]) 
	{
		if(V == fa) continue;
		g[x] = min(g[x], sum - f[V] + g[V]);
	}
//	printf("%d %lld\n", x, g[x]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	rt = 1;
	for (int i = 2; i <= n; i++) if(h[i] > h[rt]) rt = i;
	dfs(rt, rt);
	dfs2(rt, rt);
	if(G[rt].size() > 1)
	{
		ll mn1 = 0, mn2 = 0, ans = 2ll * h[rt];
		for (auto V: G[rt])
		{
			if(g[V] - f[V] < mn1)
			{
				mn2 = mn1;
				mn1 = g[V] - f[V];
			}
			else mn2 = min(mn2, g[V] - f[V]);
			ans += f[V];
		}
		ans += mn1 + mn2;
		printf("%lld\n", ans);
	}
	else
	{
		printf("%lld\n", 2ll * h[rt] + g[G[rt][0]]);
	}
	return 0;
}