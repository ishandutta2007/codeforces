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
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, F[15], G[15];
int f[2][1 << 10];
int tr[1 << 10][10];
inline void add(int &x, int y) {x += y; if(x >= mo) x -= mo;}
int main()
{
	n = read(), m = read();
	ru(i, 1, m) 
	{
		int x = read(), y = read();
		F[x] |= (1 << y), G[y] |= (1 << x);
	}
	int las = 0, now = 1;
	f[0][0] = 1;
	ru(i, 1, n)
	{
		ru(j, 0, (1 << 10) - 1) f[now][j] = 0;
		ru(j, 0, (1 << 10) - 1) ru(k, 0, 9) if(!((j >> k) & 1)) add(f[now][(j & F[k]) | G[k]], f[las][j]);
		swap(las, now);
	}
	int ans = 0;
	ru(i, 0, (1 << 10) - 1) ans = (ans + f[las][i]) % mo;
	printf("%d\n", ans);
	return 0;
}