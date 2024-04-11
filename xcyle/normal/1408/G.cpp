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
#define maxn 1505
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
inline void add(int &x, int y) {x += y; if(x >= mo) x -= mo;}
int n;
struct node {int u, v, w; inline bool operator < (const node &a) const {return w < a.w;}}p[maxn * maxn];
int f[maxn][maxn], fa[maxn], siz[maxn], cnt[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int main()
{
	n = read();
	ru(i, 1, n) ru(j, 1, n) p[(i - 1) * n + j] = {i, j, read()};
	sort(p + 1, p + n * n + 1);
	ru(i, 1, n) f[i][1] = siz[i] = 1, fa[i] = i; 
	ru(i, 1, n * n) if(p[i].u < p[i].v)
	{
		int fu = find(p[i].u), fv = find(p[i].v);
		if(fu ^ fv)
		{
			rd(i, siz[fu], 1)
			{
				rd(j, siz[fv], 1) add(f[fu][i + j], (ll)f[fu][i] * f[fv][j] % mo);
				f[fu][i] = 0;
			}
			fa[fv] = fu, siz[fu] += siz[fv], cnt[fu] += cnt[fv];
		}
		cnt[fu]++;
		if(cnt[fu] == siz[fu] * (siz[fu] - 1) / 2) add(f[fu][1], 1);
	}
	ru(i, 1, n) printf("%d ", f[find(1)][i]);
	return 0;
}