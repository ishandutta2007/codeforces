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
const int INF = 1e9;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], b[maxn];
char s[maxn][5];
int f[1 << 16][256];
int main()
{
	n = read();
	ru(i, 0, n - 1) scanf("%s%d%d", s[i], &a[i], &b[i]);
	ru(i, 0, (1 << n) - 1)
	{
		ru(j, 0, 200) f[i][j] = -INF;
	}
	f[0][0] = 0;
	ru(i, 0, (1 << n) - 1)
	{
		int cnta = 0, cntb = 0;
		ru(j, 0, n - 1) if((i >> j) & 1)
		{
			if(s[j][0] == 'R') cnta++;
			else cntb++;
		}
		ru(j, 0, n - 1) if ((i >> j) & 1) 
		{
			if(s[j][0] == 'R') cnta--;
			else cntb--;
			ru(k, min(a[j], cnta), 200)
			{
				f[i][k] = max(f[i][k], f[i ^ (1 << j)][k - min(a[j], cnta)] + min(b[j], cntb));
			}
			if(s[j][0] == 'R') cnta++;
			else cntb++;
		} 
	}
	int tota = 0, totb = 0;
	ru(i, 0, n - 1) tota += a[i], totb += b[i];
	int ans = INF;
	ru(i, 0, 200)
	{
		ans = min(ans, max(tota - i, totb - f[(1 << n) - 1][i]));
	}
	printf("%d\n", ans + n);
	return 0;
}