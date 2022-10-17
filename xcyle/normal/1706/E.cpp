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
#define maxn 100005
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, q, dep[maxn], fa[maxn];
vector<pii> G[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int anc[maxn][22], path[maxn][22];
void init(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	ru(i, 1, 20) path[x][i] = max(path[x][i - 1], path[anc[x][i - 1]][i - 1]), anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (auto t: G[x])
	{
		int V = t.fi;
		if(V == fa) continue;
		anc[V][0] = x, path[V][0] = t.se, init(V, x);
	}
}
inline int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	rd(i, 20, 0) if(dep[anc[y][i]] >= dep[x]) y = anc[y][i];
	if(x == y) return x;
	rd(i, 20, 0) if(anc[x][i] ^ anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
inline int jump(int x, int h)
{
	int res = 0;
	ru(i, 0, 20) if((h >> i) & 1) res = max(res, path[x][i]), x = anc[x][i];
	return res;
}
int LOG[maxn], mx[maxn][22];
void solve()
{
	n = read(), m = read(), q = read();
	ru(i, 1, n) fa[i] = i, G[i].clear();
	ru(i, 1, m)
	{
		int x = read(), y = read(); 
		if(find(x) != find(y))
		{
			G[x].push_back(make_pair(y, i));
			G[y].push_back(make_pair(x, i));
			fa[find(x)] = y;
		}
	}
	init(1, 0);
	rd(i, n - 1, 0)
	{
		int tmp = lca(i, i + 1);
		mx[i][0] = max(jump(i, dep[i] - dep[tmp]), jump(i + 1, dep[i + 1] - dep[tmp]));
		ru(j, 1, 20) if(i + (1 << j) - 1 < n)
		{
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}
	ru(i, 1, q)
	{
		int l = read(), r = read() - 1;
		if(l > r) {printf("0 "); continue;}
		int len = LOG[r - l + 1];
		printf("%d ", max(mx[l][len], mx[r - (1 << len) + 1][len]));
	}
	printf("\n");
}
int main()
{
	ru(i, 2, maxn - 1) LOG[i] = LOG[i >> 1] + 1;
	int T = read();
	while(T--) solve();
	return 0;
}