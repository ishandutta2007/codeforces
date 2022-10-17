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
int T, n, m, fl, vis[maxn], vis2[maxn];
vector<int> G[maxn];
inline void check(int x)
{
	vis[x] = 1;
	vis2[x] = 1;
	for (auto V: G[x])
	{
		if(!vis[V]) check(V);
		else fl &= vis2[V];
	}
	vis2[x] = 0;
}
int ans[maxn], ans2[maxn], fa[maxn];
void dfs(int x)
{
	vis[x] = 1;
	for (auto V: G[x])
	{
		if(!vis[V])
		{
			dfs(V);
			ans[x] += ans[V];
			ans2[x] += ans2[V];
		}
		else
		{
			ans[V]--;
			ans[x]++;
			ans2[V] -= V;
			ans2[x] += V;
		}
	}
}
void dfs2(int x)
{
	vis[x] = 1;
	if(ans[x] == 1)
	{
		ans[x] = max(ans[x], ans[ans2[x]]);
	}
	for (auto V: G[x])
	{
		if(!vis[V]) dfs2(V);
	}
}
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y);
	}
	int rt;
	for (int i = 1; i <= 100; i++)
	{
		fl = 1;
		for (int j = 1; j <= n; j++) vis[j] = vis2[j] = 0;
		rt = (ll)rand() * rand() % n + 1;
		check(rt);
		if(fl) break;
		if(i == 100)
		{
			printf("-1\n");
			return;
		}
	}
//	printf("!!!%d\n", rt);
	for (int i = 1; i <= n; i++) vis[i] = ans[i] = ans2[i] = 0;
	dfs(rt);
//	for (int i = 1; i <= n; i++) printf("%d  ",ans[i]);
//	printf("\n");
	for (int i = 1; i <= n; i++) vis[i] = 0;
	dfs2(rt);
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
	{
		if(ans[i] < 2) cnt++;
	}
	if(cnt * 5 < n) printf("-1\n");
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if(ans[i] < 2) printf("%d ", i);
		}
		printf("\n");
	}
}
int main()
{
	srand(time(NULL));
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}