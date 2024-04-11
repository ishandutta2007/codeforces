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
#define maxn 15 
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int f[15][35][15][15], vis[15], inv[15];
void dfs(int len, int step, int mx, int num1, int num2, int las)
{
	if(num1 > 11 || num2 > 11) return;
//	printf("%d %d %d %d %d %d\n", len, step, mx, num1, num2, las);
	if(step > len){f[1][len][num1][num2]++; /*printf("! %d %d %d\n", len, num1, num2);*/ return;}
	if(mx < step) return;
	rd(i, len, 1)
	{
		if(vis[i]) num1++;
		else
		{
			vis[i] = 1;
			dfs(len, step + 1, max(mx, i), num1, num2 + (las > i), i);
			vis[i] = 0;
		}
	}
}
inline void add(int &x, int y) {x += y; if(x >= mo) x -= mo;}
void init()
{
	int L = 12;
	inv[1] = 1; ru(i, 2, L) inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
	ru(i, 2, L) inv[i] = (ll)inv[i] * inv[i - 1] % mo;
	ru(i, 2, L) dfs(i, 1, 1, 0, 0, 0);
	ru(lev, 2, L) ru(n1, 1, 2 * L) ru(l1, 1, n1) ru(n2, 1, L) ru(l2, 1, n2) ru(n3, 1, L) ru(l3, 1, n3) 
		add(f[lev][n1][n2][n3], (ll)f[lev - 1][l1][l2][l3] * f[1][n1 - l1][n2 - l2][n3 - l3] % mo);
	ru(lev, 1, L) ru(n1, 1, 2 * L) ru(n2, 1, L) ru(n3, 1, L) f[lev][n1][n2][n3] = (ll)f[lev][n1][n2][n3] * inv[lev] % mo;
}
void solve()
{
	int n = read(), k = read(), x = read(), ans = 0;
	if(!k) ans = (x == 0 ? 1 : 0);
	else 
	{
		ru(j, 1, min(2 * k, n))
		{
			int tmp = 1;
			ru(i, 1, min(k + 1, n))
			{
				tmp = (ll)tmp * (n - j + i) % mo;
				add(ans, (ll)tmp * f[i][j][k][x] % mo);
//				printf("%d %d %d %d %d %d\n", i, j, k, x, f[i][j][k][x], tmp);
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	init();
	int T = read(); while(T--) solve();
	return 0;
}