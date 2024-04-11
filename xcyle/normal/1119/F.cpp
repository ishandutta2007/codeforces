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
#define maxn 250005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, id[maxn], d[maxn], rk[maxn], now, vis[maxn];
vector<int> G[maxn], val[maxn], T[maxn], w[maxn], s;
multiset<ll> q1[maxn], q2[maxn];
multiset<ll>::iterator it;
ll sum[maxn], ans[maxn], f[maxn], g[maxn], TOT;
inline bool cmp(int x, int y)
{
	return d[x] > d[y];
}
inline void upd(int x)
{
	while(q1[x].size() < now - 1 && !q2[x].empty())
	{
		it = q2[x].end(); it--;
		ll tmp = (*it);
		sum[x] += tmp;
		q2[x].erase(q2[x].find(tmp));
		q1[x].insert(tmp);
	}
	while(q1[x].size() >= now) 
	{
		ll tmp = *(q1[x].begin());
//		printf("?????? %d %lld\n", x, tmp);
		sum[x] -= tmp;
		q1[x].erase(q1[x].find(tmp));
		q2[x].insert(tmp);
	}
}
inline void add(int x, ll d)
{
//	printf("$%lld %lld $", x, d);
	if(!q1[x].empty()  && d >= (*(q1[x].begin()))) q1[x].insert(d), sum[x] += d;
	else q2[x].insert(d);
}
inline void del(int x, ll d)
{
	if(q1[x].find(d) != q1[x].end()) q1[x].erase(q1[x].find(d)), sum[x] -= d;
	else q2[x].erase(q2[x].find(d));
}
void dfs(int x, int fa)
{
	vis[x] = 1;
	for (auto V: G[x]) if(V != fa) dfs(V, x);
//	printf("!!!");
//	for (auto y: q1[x]) printf("%lld ", y);
//	for (auto y: q2[x]) printf("%lld ", y);
	f[x] = g[x] = 0;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i], W = val[x][i];
		if(V == fa) continue;
		f[x] += g[V];
		if(f[V] - g[V] + W > 0) add(x, f[V] - g[V] + W);
	}
	upd(x);
//	for (auto y: q1[x]) printf("%lld ", y);
//	printf("   ");
//	for (auto y: q2[x]) printf("%lld ", y);
//	printf("%lld ", f[x]);
	f[x] += sum[x];
	g[x] = f[x];
	if(!q2[x].empty())
	{
		it = q2[x].end(); it--;
		g[x] = f[x] + max(0ll, (*it));
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i], W = val[x][i];
		if(V == fa) continue;
		if(f[V] - g[V] + W > 0) del(x, f[V] - g[V] + W);
	}
//	printf("%d %lld %lld\n", x, f[x], g[x]);
}
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	n = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read(), tmp = read();
		T[x].push_back(y), T[y].push_back(x), w[x].push_back(tmp), w[y].push_back(tmp);
		d[x]++, d[y]++;
		ans[0] += tmp;
	}
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) rk[id[i]] = i;
	int j = 1; 
	for (now = n - 1; now >= 1; now--)
	{
		for (; j <= n && d[id[j]] > now; j++)
		{
			s.push_back(id[j]);
			for (int k = 0; k < T[id[j]].size(); k++)
			{
				int V = T[id[j]][k], W = w[id[j]][k];
				if(rk[V] < j)
				{
					G[id[j]].push_back(V), val[id[j]].push_back(W);
					G[V].push_back(id[j]), val[V].push_back(W);
					del(V, W);
				}
				else
				{
					TOT += W;
					add(id[j], W);
				}
			}
		}
		for (auto x: s) vis[x] = 0;
//		for (auto x: s) printf("%d ", x);
//		printf("\n");
		ans[now] = TOT;
		for (auto x: s) if(!vis[x]) dfs(x, x), ans[now] -= g[x];
	}
	for (int i = 0; i < n; i++) printf("%lld ", ans[i]);
	return 0;
}