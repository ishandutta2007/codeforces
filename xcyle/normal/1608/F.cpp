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
#define maxn 2005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, l[maxn], r[maxn], c[maxn][maxn], f[2][maxn][maxn];
inline void upd(int &x, int y) {x += y; if(x >= mo) x -= mo;}
int main()
{
	n = read(), k = read();
	ru(i, 0, n)
	{
		c[i][0] = c[i][i] = 1;
		ru(j, 1, i - 1) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
	}
	ru(i, 1, n) 
	{
		int x = read();
		l[i] = max(0, x - k), r[i] = min(n, x + k);
	}
	int las = 0, now = 1;
	ru(i, l[n], r[n]) ru(j, 1, n + 1 - i) f[las][i][j] = c[n - i][j - 1];
	rd(i, n - 1, 0) 
	{
		ru(k, 1, n + 1)
		{
			int sum = 0;
			rd(j, r[i + 1], max(r[i] + 1, l[i + 1])) upd(sum, f[las][j][k - 1]);
			rd(j, r[i], l[i])
			{
				ll tmp = sum + (ll)f[las][j][k] * (n - k + 1) + (ll)f[las][j][k - 1] * (n - j + 1 - (k - 1));
				f[now][j][k] = tmp % mo;
				upd(sum, f[las][j][k - 1]);
			}
		}
		ru(k, 1, n + 1) ru(j, l[i + 1], r[i + 1]) f[las][j][k] = 0;
		swap(las, now);
	}
	printf("%d\n", f[las][0][n + 1]);
	return 0;
}