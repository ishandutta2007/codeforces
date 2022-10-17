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
#define maxn 1600005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q, dep[maxn], f[maxn], buc[maxn][2], cnt[maxn];
char s[maxn];
vector<int> T[maxn], G[maxn];
void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1, f[x] = fa;
	for (auto V: T[x]) if(V ^ fa) dfs(V, x);
}
inline void add(int x, int y)
{
	G[x].push_back(y), G[y ^ 1].push_back(x ^ 1);
}
inline void foo(int x, int ch, int to)
{
	if(cnt[x] < 2 && buc[x][0] != ch && buc[x][1] != ch) buc[x][cnt[x]++] = ch;
	if(buc[x][0] != ch) add(x * 2, to);
	if(buc[x][1] != ch) add(x * 2 + 1, to);
}
void work(int x, int y, int t)
{
	int l = 1, r = strlen(s + 1);
	while(l <= r)
	{
		if(dep[x] > dep[y]) foo(x, s[l++] - 'a' + 1, t), x = f[x];
		else foo(y, s[r--] - 'a' + 1, t), y = f[y];
	}
}
int dfn[maxn], low[maxn], vis[maxn], sta[maxn], top, tot;
int bel[maxn], Cnt, vis2[maxn];
void tarjan(int x)
{
	dfn[x] = low[x] = ++tot;
	sta[++top] = x, vis[x] = 1;
	for (auto V: G[x])
	{
		if(!dfn[V]) tarjan(V), low[x] = min(low[x], low[V]);
		else if(vis[V]) low[x] = min(low[x], dfn[V]); 
	}
	if(low[x] == dfn[x])
	{
		Cnt++;
		for (; sta[top] != x; top--) bel[sta[top]] = Cnt, vis[sta[top]] = 0;
		bel[x] = Cnt, vis[x] = 0, top--;
	}
}
int main()
{
	n = read(), q = read();
	for (int i = 1; i < n; i++) {int x = read(), y = read(); T[x].push_back(y), T[y].push_back(x);}
	dfs(1, 1);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d%s", &x, &y, s + 1);
		work(x, y, (n + i) * 2);
		work(y, x, (n + i) * 2 + 1);
	}
	for (int i = 2; i <= 2 * (n + q) + 1; i++) if(!dfn[i]) tarjan(i);
	for (int i = 1; i <= n + q; i++)
	{
		if(bel[2 * i] < bel[2 * i + 1]) vis2[bel[2 * i]] = vis[2 * i] = 1;
		else vis2[bel[2 * i + 1]] = vis[2 * i + 1] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if(!buc[i][0]) buc[i][0] = 1;
		if(!buc[i][1]) buc[i][1] = buc[i][0] % 26 + 1;
	}
	for (int i = 2; i <= 2 * (n + q) + 1; i++) for (auto V: G[i]) if(vis2[bel[i]] && !vis2[bel[V]])
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 2; i <= 2 * (n + q) + 1; i++) if(vis[i] != vis2[bel[i]])
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
	{
		if(bel[2 * i] < bel[2 * i + 1]) printf("%c", 'a' + buc[i][0] - 1);
		else printf("%c", 'a' + buc[i][1] - 1);
	}
	return 0;
}