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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], pre[maxn][maxn], suf[maxn][maxn];
void solve()
{
	n = read(); ru(i, 1, n) a[i] = read();
	ru(i, 1, n)
	{
		ru(j, 1, n) pre[i][j] = pre[i - 1][j];
		pre[i][a[i]]++;
	}
	ru(j, 1, n) suf[n + 1][j] = 0; 
	rd(i, n, 1)
	{
		ru(j, 1, n) suf[i][j] = suf[i + 1][j];
		suf[i][a[i]]++;
	}
	ru(i, 1, n) ru(j, 1, n) pre[i][j] += pre[i][j - 1], suf[i][j] += suf[i][j - 1];
	ll ans = 0;
	ru(i, 1, n)
	{
		ru(j, i + 1, n)
		{
			ans += (ll)pre[i - 1][a[j] - 1] * suf[j + 1][a[i] - 1];
		}
	}
	printf("%lld\n", ans);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}