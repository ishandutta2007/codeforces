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
#define mid ((l + r + 1) >> 1)
#define maxn 400005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, r, anc[maxn][22], fa[maxn], dis[maxn], dep[maxn];
vector<int> G[maxn]; queue<int> q;
void dfs(int x, int fa)
{
	dep[x] = dep[anc[x][0] = fa] + 1; ru(i, 1, 20) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (auto V: G[x]) if(V ^ fa) dfs(V, x);
}
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
inline int lca(int x, int y)
{
	rd(i, 20, 0) if(dep[anc[y][i]] >= dep[x]) y = anc[y][i];
	if(x == y) return x;
	rd(i, 20, 0) if(anc[x][i] ^ anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
inline int jump(int x, int h)
{
	rd(i, 20, 0) if((h >> i) & 1) x = anc[x][i];
	return x;
}
void query(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	int z = lca(x, y), len = dep[x] + dep[y] - 2 * dep[z];
	if(len <= 2 * k) {printf("YES\n"); return;}
	if(dep[x] - dep[z] >= k) x = jump(x, k);
	else x = jump(y, len - k);
	y = jump(y, k);
	if(find(x) == find(y)) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	n = read(), k = read(), r = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		if(k & 1)
		{
			G[x].push_back(n + i), G[n + i].push_back(x);
			G[y].push_back(n + i), G[n + i].push_back(y);
		}
		else G[x].push_back(y), G[y].push_back(x);
	}
	if(k & 1) k *= 2, n = 2 * n - 1; k /= 2;
	dfs(1, 0);
	ru(i, 1, n) fa[i] = i, dis[i] = n;
	while(r--) {int x = read(); dis[x] = 0, q.push(x);}
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		if(dis[x] == k) continue;
		for (auto V: G[x]) if(find(V) != find(x))
		{
			fa[find(V)] = find(x);
			if(dis[V] > dis[x] + 1) dis[V] = dis[x] + 1, q.push(V);
		}
	}
	int q = read(); while(q--) query(read(), read());
	return 0;
}