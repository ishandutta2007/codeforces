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
#define maxn 3605
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n[2], k, fac[maxn], ifac[maxn], vis[2][maxn]; 
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo; 
	}
	return res;
}
inline void upd(int &x, int y) {x += y; if(x >= mo) x -= mo;}
int f[2][maxn][maxn];
void init()
{
	ru(t, 0, 1)
	{
		f[t][0][0] = 1;
		ru(i, 1, n[t])
		{
			ru(j, 0, i / 2) f[t][i][j] = f[t][i - 1][j];
			if(i > 1 && !vis[t][i] && !vis[t][i - 1]) ru(j, 1, i / 2) upd(f[t][i][j], f[t][i - 2][j - 1]);
		}
	}
} 
inline int calc(int x, int y)
{
	if(x < y || y < 0) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo; 
}
int main()
{
	fac[0] = ifac[0] = 1; ru(i, 1, maxn - 1) fac[i] = (ll)fac[i - 1] * i % mo, ifac[i] = qpow(fac[i], mo - 2);
	n[0] = read(), n[1] = read(), k = read();
	ru(i, 1, k)
	{
		int xl = read(), yl = read(), xr = read(), yr = read();
		vis[0][xl] = vis[0][xr] = vis[1][yl] = vis[1][yr] = 1; 
	}
	init();
	int ans = 0;
	int realn[2] = {0, 0}; ru(t, 0, 1) ru(i, 1, n[t]) realn[t] += 1 - vis[t][i];
//	printf("%d %d\n", realn[0], realn[1]);
//	ru(i, 0, n[0])
//	{
//		printf("%d ", f[0][n[0]][i]);
//	}
//	printf("\n");
//	ru(i, 0, n[1])
//	{
//		printf("%d ", f[1][n[1]][i]);
//	}
//	printf("\n");
	ru(i, 0, n[0]) ru(j, 0, n[0])
	{
		if(2 * i + j > realn[0] || i + 2 * j > realn[1]) break;
		int res = (ll)f[0][n[0]][i] * calc(realn[0] - 2 * i, j) % mo * f[1][n[1]][j] % mo * calc(realn[1] - 2 * j, i) % mo;
		upd(ans, (ll)res * fac[i] % mo * fac[j] % mo);
	}
	printf("%d\n", ans);
	return 0;
}