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
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
vector<int> G[maxn];
int n, m, anc[maxn][25];
int dep[maxn], dfn[maxn], siz[maxn], tot;
struct path
{
	int x, y, typ;
	inline int friend operator < (path a, path b)
	{
		return (a.typ && b.typ) ? dep[a.x] > dep[b.x] : a.typ;
	}
}p[maxn];
void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	siz[x] = 1;
	dfn[x] = ++tot;
	anc[x][0] = fa;
	for (int i = 1; i <= 20; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (int i = 0; i < G[x].size(); i++)
	{
		dfs(G[x][i], x);
		siz[x] += siz[G[x][i]];
	}
}
int t[maxn];
void add(int x)
{
	for (; x <= n; x += (x & (-x))) t[x]++;
}
int que(int x)
{
	int res = 0;
	for (; x; x -= (x & (-x))) res += t[x];
	return res;
}
int query(int x)
{
	return que(dfn[x] + siz[x] - 1) - que(dfn[x] - 1);
}
int find(int x, int step)
{
	for (int i = 20; i >= 0; i--)
	{
		if((step >> i) & 1) x = anc[x][i];
	}
	return x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
	{
		int u = read();
		G[u].push_back(i);
	}
	dfs(1, 1);
	for (int i = 1; i <= m; i++)
	{
		p[i].x = read(), p[i].y = read();
		if(dep[p[i].x] > dep[p[i].y]) swap(p[i].x, p[i].y);
		p[i].typ = (dfn[p[i].x] <= dfn[p[i].y] && dfn[p[i].y] < dfn[p[i].x] + siz[p[i].x]);
		if(dep[p[i].y] - 1 == dep[p[i].x] && p[i].typ)
		{
			printf("-1\n");
			return 0;
		}
	}
	sort(p + 1, p + m + 1);
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if(!p[i].typ)
		{
			if(ans - query(p[i].x) - query(p[i].y)) continue;
			ans++;
			break;
		}
		int tmp = find(p[i].y, dep[p[i].y] - dep[p[i].x] - 1);
		if(query(tmp) - query(p[i].y)) continue;
		ans++, add(dfn[tmp]);
	}
	printf("%d\n", ans);
	return 0;
}