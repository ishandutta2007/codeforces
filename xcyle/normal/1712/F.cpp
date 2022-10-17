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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, X, fa[maxn], siz[maxn], hig[maxn], pre[maxn], maxson[maxn];
int f[maxn], g[maxn], val[maxn], ans;
vector<int> G[maxn];
void dfs1(int x)
{
	if(G[x].empty() || (x == 1 && G[x].size() == 1)) f[x] = 0;
	for (auto V: G[x]) dfs1(V), f[x] = min(f[x], f[V] + 1);
}
void dfs2(int x)
{
	if(G[x].empty() || (x == 1 && G[x].size() == 1)) g[x] = 0;
	pre[0] = g[x];
	ru(i, 0, (int)G[x].size() - 1) pre[i + 1] = min(pre[i], f[G[x][i]] + 1);
	int suf = g[x];
	rd(i, (int)G[x].size() - 1, 0)
	{
		g[G[x][i]] = min(pre[i], suf) + 1;
		suf = min(suf, f[G[x][i]] + 1);
	}
	for (auto V: G[x]) dfs2(V);
	val[x] = min(f[x], g[x]);
}
void dfs(int x, int pos)
{
	f[pos] = val[x];
	if(maxson[x]) 
	{
		dfs(maxson[x], pos + 1);
		while(ans <= hig[maxson[x]] && f[pos + ans + 1] + f[pos] + X > ans) ans++;
		f[pos] = max(f[pos], f[pos + 1]);
	}
	int now = pos + 1 + siz[maxson[x]];
	for (auto V: G[x]) if(V ^ maxson[x])
	{
		dfs(V, now);
		ru(i, 0, hig[V])
		{
			while(ans + 1 - i - 1 <= hig[x] && f[pos + max(0, ans + 1 - i - 1)] + f[now + i] + X > ans) ans++;
		}
		ru(i, 0, hig[V]) f[pos + i + 1] = max(f[pos + i + 1], f[now + i]);
		rd(i, hig[V], 0) f[pos + i] = max(f[pos + i], f[pos + i + 1]);
		now += siz[V];
	}
//	printf("%d %d  ", x, pos);
//	ru(i, 0, hig[x]) printf("%d ", f[pos + i]); printf("\n");
}
int main()
{
	n = read();
	ru(i, 2, n) G[fa[i] = read()].push_back(i);
	rd(i, n, 1) 
	{
		siz[i]++, f[i] = g[i] = n;
		siz[fa[i]] += siz[i];
		hig[fa[i]] = max(hig[fa[i]], hig[i] + 1);
		if(hig[i] >= hig[maxson[fa[i]]]) maxson[fa[i]] = i;
	}
	dfs1(1), dfs2(1);
//	ru(i, 1, n) printf("%d %d %d %d %d %d\n", i, hig[i], siz[i], maxson[i], f[i], g[i]);
	int q = read();
	while(q--) X = read(), ans = 0, dfs(1, 1), printf("%d ", ans);
	return 0;
}