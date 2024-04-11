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
#define maxm 200005
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, q, ans[maxm];
int u[maxm], v[maxm];
struct node
{
	int s, t, r, id;
};
vector<node> que[maxm];
int f[maxn][maxn];
int main()
{
	n = read(), m = read(), q = read();
	ru(i, 1, m) u[i] = read(), v[i] = read();
	ru(i, 1, q)
	{
		int l = read(), r = read(), s = read(), t = read();
		que[l].push_back({s, t, r, i});
	}
	ru(i, 1, n) ru(j, 1, n) f[i][j] = m + 1;
	rd(i, m, 1)
	{
		ru(j, 1, n) f[j][j] = i;
		ru(j, 1, n) f[u[i]][j] = f[v[i]][j] = min(f[u[i]][j], f[v[i]][j]);
		for (auto V: que[i]) ans[V.id] = (f[V.s][V.t] <= V.r);
	}
	ru(i, 1, q) ans[i] ? printf("Yes\n") : printf("No\n");
	return 0;
}