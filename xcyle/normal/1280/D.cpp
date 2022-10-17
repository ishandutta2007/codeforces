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
#define maxn 3005
using namespace std;
const int mo = 1e9 + 7;
const ll INF = 1e18;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, siz[maxn];
ll a[maxn];
vector<int> G[maxn];
struct node
{
	int cnt; ll s;
	inline node operator + (const node &a) const
	{
		return (node){cnt + a.cnt, s + a.s};
	}
	inline bool operator < (const node &a) const
	{
		return cnt == a.cnt ? s > a.s : cnt > a.cnt;
	}
};
inline node MAX(node a, node b)
{
	return a < b ? a : b;
}
node f[maxn][maxn];
node tmp[maxn];
void dfs(int x, int fa)
{
	siz[x] = 0;
	f[x][0] = {0, a[x]};
	for (auto V: G[x]) if(V ^ fa)
	{
		dfs(V, x);
		ru(i, 0, siz[x] + siz[V]) tmp[i] = (node){0, -INF};
		rd(i, siz[x], 0) rd(j, siz[V], 0)
		{
			tmp[i + j] = MAX(tmp[i + j], f[x][i] + f[V][j]);
		}
		ru(i, 0, siz[x] + siz[V]) f[x][i] = tmp[i];
		siz[x] += siz[V];
	}
	rd(i, siz[x], 0)
	{
		f[x][i + 1] = MAX(f[x][i + 1], (node){f[x][i].cnt + (f[x][i].s > 0), 0});
	}
	siz[x]++;
//	printf("%d:  \n", x);
//	ru(i, 0, siz[x]) printf("%d %lld  ", f[x][i].cnt, f[x][i].s);
//	printf("\n");
}
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) a[i] = -read(), G[i].clear();
	ru(i, 1, n) a[i] += read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	ru(i, 1, n) ru(j, 0, n) f[i][j] = {0, -INF};
	dfs(1, 0);
	printf("%d\n", f[1][m - 1].cnt + (f[1][m - 1].s > 0));
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}