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
#define maxn 5000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m;
char s[maxn];
int f[maxn], g[maxn];
int sumf[maxn], sumg[maxn];
void solve()
{
	n = read(), m = read();
	ru(i, 1, 2 * n * m) s[i] = '0';
	scanf("%s", s + 2 * n * m + 1);
	ru(i, 1, 3 * n * m) sumf[i] = sumg[i] = 0;
	ru(i, 1, n * m * 3)
	{
		f[i] = f[i - 1] + s[i] - '0';
		g[i] = (i >= m ? g[i - m] : 0) + s[i] - '0';
		if(i >= m && f[i] - f[i - m] == 0) sumf[i]++, sumf[i + n * m]--;//, printf("%d\n", i);
		if(i >= n * m && g[i] - g[i - n * m] == 0) sumg[i]++, sumg[i + m]--;
	}
	ru(i, 1, 3 * n * m) sumg[i] += sumg[i - 1], sumf[i] += (i >= m ? sumf[i - m] : 0);
	ru(i, 2 * n * m + 1, n * m * 3) printf("%d ", n + m - sumf[i] - sumg[i]);
	printf("\n");
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}