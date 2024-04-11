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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, p, k;
ll x, y;
char s[maxn];
ll f[maxn];
void solve()
{
	n = read(), p = read(), k = read();
	scanf("%s", s + 1);
	x = read(), y = read();
	ll ans = 1e16;
	rd(i, n, 1)
	{
		if(i + k > n) f[i] = 0;
		else f[i] = f[i + k];
		if(s[i] == '0') f[i] += x;
	}
	rd(i, n, p) ans = min(ans, + y * (i - p) + f[i]);
	printf("%lld\n", ans);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}