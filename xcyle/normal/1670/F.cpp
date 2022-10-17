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
#define maxn 1005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, c[maxn][maxn];
int f[100][maxn][2];
inline void add(int &x, int y) {x += y; if(x >= mo) x -= mo;}
int calc(ll r, ll z)
{
	f[0][0][0] = 1;
	ru(i, 0, 60)
	{
		ru(j, 0, n) ru(k, 0, 1) f[i + 1][j][k] = 0;
		ru(las, 0, n) ru(now, 0, n)
		{
			if((now & 1) != ((z >> i) & 1)) continue;
			int s = 2 * ((las + now) & 1);
			add(f[i + 1][(las + now) / 2][s > 2 * ((r >> i) & 1)], (ll)f[i][las][0] * c[n][now] % mo);
			add(f[i + 1][(las + now) / 2][s + 1 > 2 * ((r >> i) & 1)], (ll)f[i][las][1] * c[n][now] % mo);
		}
	}
	return f[61][0][0];
}
int main()
{
	n = read();
	ru(i, 0, n)
	{
		c[i][0] = c[i][i] = 1;
		ru(j, 1, i - 1) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
	}
	ll l, r, z; scanf("%lld%lld%lld", &l, &r, &z);
	printf("%d\n", (mo + calc(r, z) - calc(l - 1, z)) % mo);
	return 0;
}