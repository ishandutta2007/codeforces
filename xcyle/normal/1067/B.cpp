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
#define maxn 100005
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, d[maxn], vis[maxn];
vector<int> G[maxn];
int dep[maxn], ff[maxn] ,flag;
int rt;
void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	ff[x] = fa;
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		dfs(V, x);
	}
}
void check(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	if(dep[x] == k)
	{
		if(G[x].size() > 1) flag = 0;
		return;
	}
	if(dep[x] > k)
	{
		flag = 0;
		return;
	}
	if(G[x].size() < 4)
	{
		flag = 0;
		return;
	}
	if(G[x].size() == 1 && dep[x] < k)
	{
		flag = 0;
		return;
	}
	for (int i = 0; i < G[x].size(); i++)
	{
		int V = G[x][i];
		if(V == fa) continue;
		check(V, x);
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		d[u]++, d[v]++; 
	}
	int y = -1, x = 0;
	for (int i = 1; i <= n; i++)
	{
		if(d[i] == 1) y = i;
	}
	dfs(y, y);
	for (int i = 1; i <= n; i++)
	{
		if(dep[i] > dep[x]) x = i;
	}
	if(dep[x] != 2 * k + 1) 
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= k; i++) x = ff[x];
	rt = x;
	flag = 1;
	G[rt].push_back(0);
	dep[0] = -1;
	check(rt, 0);
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}