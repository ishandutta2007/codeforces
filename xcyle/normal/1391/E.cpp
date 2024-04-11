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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, m, siz[maxn], fa[maxn], dep[maxn], d[maxn], vis[maxn], maxson[maxn];
vector<int> G[maxn];
void dfs(int x)
{	
	vis[x] = siz[x] = 1;
	for (auto V: G[x]) if(!vis[V])
	{
		fa[V] = x, dep[V] = dep[x] + 1;
		dfs(V), siz[x] += siz[V];
		if(siz[V] > siz[maxson[x]]) maxson[x] = V;
	}
}
vector<int> t[maxn];
struct cmp
{
	inline bool operator ()(int x, int y)
	{
		return t[x].size() < t[y].size();
	}
};
priority_queue<int, vector<int>, cmp> q;
void dfs3(int x, int bel)
{
	t[bel].push_back(x);
	for (auto V: G[x]) if(dep[V] == dep[x] + 1) dfs3(V, bel);
}
void dfs2(int x)
{
	if(2 * siz[maxson[x]] <= (n - dep[x]))
	{
		for (auto V: G[x]) if(dep[V] == dep[x] + 1) dfs3(V, V), q.push(V);
		return;
	}
	for (auto V: G[x]) if(dep[V] == dep[x] + 1 && V != maxson[x]) dfs3(V, V), q.push(V); 
	dfs2(maxson[x]);
}
void solve()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) maxson[i] = 0, vis[i] = 0, G[i].clear(), d[i] = 0, t[i].clear();
	for (int i = 1; i <= m; i++) {int x = read(), y = read(); d[x]++, d[y]++, G[x].push_back(y), G[y].push_back(x);}
	d[1]++, dep[1] = 1, dfs(1);
	for (int i = 1; i <= n; i++)
	{
		if(dep[i] * 2 >= n)
		{
			printf("PATH\n%d\n", dep[i]);
			for (int now = i; now; now = fa[now]) printf("%d ", now);
			printf("\n"); return;
		}
	}
	int cnt = (n + 3) / 4; printf("PAIRING\n%d\n", cnt);
	while(!q.empty()) q.pop(); dfs2(1);
	for (int i = 1; i <= cnt; i++)
	{
		int a = q.top(); q.pop(); int b = q.top(); q.pop();
		printf("%d %d\n", t[a].back(), t[b].back());
		t[a].pop_back(), t[b].pop_back();
		q.push(a), q.push(b);
	}
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}