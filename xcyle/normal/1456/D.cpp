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
#define maxn 5005
#define int long long
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, x[maxn], t[maxn], f[maxn][maxn], f2[maxn], g[maxn];
signed main()
{
	n = read(); ru(i, 1, n) t[i] = read(), x[i] = read(), g[i] = 1e9 + 1;
	f2[0] = 1;
	ru(i, 0, n - 1)
	{
		f2[i + 1] = f2[i] & (abs(x[i + 1] - x[i]) <= t[i + 1] - t[i]);
		ru(j, 1, n) if(abs(x[i + 1] - x[i]) <= t[i + 1] - t[i]) f[i + 1][j] |= f[i][j];
		ru(j, 1, n) if(abs(x[i + 1] - x[j]) + abs(x[j] - x[i]) <= t[i + 1] - t[i]) f[i + 1][j] |= f2[i];
		if(f2[i]) g[i + 1] = min(g[i + 1], t[i] + abs(x[i + 1] - x[i]));
		if(f[i][i + 1])
		{
			g[i + 2] = min(g[i + 2], t[i] + abs(x[i + 2] - x[i]));
			f2[i + 2] |= (t[i] + abs(x[i + 2] - x[i]) <= t[i + 2]);
			ru(j, 1, n) f[i + 2][j] |= (max(t[i + 1], t[i] + abs(x[j] - x[i])) + abs(x[i + 2] - x[j]) <= t[i + 2]);
		}
		f2[i + 1] |= (g[i] + abs(x[i + 1] - x[i]) <= t[i + 1]);
		ru(j, 1, n) f[i + 1][j] |= (max(t[i], g[i] + abs(x[i] - x[j])) + abs(x[j] - x[i + 1]) <= t[i + 1]);
		g[i + 1] = max(min(g[i + 1], g[i] + abs(x[i + 1] - x[i])), t[i]);
		if(g[i + 1] > t[i + 1]) g[i + 1] = 1e9 + 1;
	}
	(g[n] <= t[n] || f2[n] || f[n - 1][n]) ? printf("YES") : printf("NO");
	return 0;
}