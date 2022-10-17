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
#define maxn 305
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, siz[maxn];
vector<int> G[maxn];
int f[maxn][maxn], g[maxn][maxn], tf[maxn], tg[maxn];
inline void add(int &x, int y) {x += y; if(x >= mo) x -= mo;}
void dfs(int x, int fa, int l)
{
	f[x][0] = g[x][0] = siz[x] = 1;
	for (auto V: G[x]) if(V ^ fa)
	{
		dfs(V, x, l);
		ru(j, 0, siz[x]) tf[j] = f[x][j], tg[j] = g[x][j], f[x][j] = g[x][j] = 0;
		ru(j, 0, siz[x])
		{
			ru(k, 0, siz[V])
			{
				add(f[x][min(j, k + 1)], (ll)tf[j] * f[V][k] % mo); 
				add(g[x][max(j, k + 1)], (ll)tg[j] * g[V][k] % mo);
			}
		}
		ru(j, 0, siz[x])
		{
			ru(k, 0, siz[V])
			{
				if(j + k + 1 <= l) add(f[x][j], (ll)tf[j] * g[V][k] % mo), add(f[x][k + 1], (ll)tg[j] * f[V][k] % mo);
				else add(g[x][k + 1], (ll)tf[j] * g[V][k] % mo), add(g[x][j], (ll)tg[j] * f[V][k] % mo);
			}
		}
		siz[x] += siz[V];
	}
}
int main()
{
	n = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	int ans = n, tmp = 1;
	ru(i, 1, n) tmp = (ll)tmp * ((mo + 1) / 2) % mo;
	ru(i, 0, n)
	{
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		dfs(1, 0, i);
		int sum = 0;
		ru(j, 0, n) ans = (ans + mo - (ll)tmp * f[1][j] % mo) % mo, add(sum, f[1][j]);
	}
	printf("%d\n", ans); 
	return 0;
}