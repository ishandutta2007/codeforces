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
int n, c, p[maxn];
ll a[maxn];
int main()
{
	n = read(), c = read();
	ll ans = 0;
	ru(i, 1, n) p[i] = read(), ans += p[i];
	ru(i, 1, n) a[i] = (ll)c * (n - i) + read() - p[i];
	sort(a + 1, a + n + 1);
	ll sum = ans;
	ru(i, 1, n) ans = min(ans, sum += a[i] - (ll)c * (i - 1));//, cerr<<ans<<endl;
	printf("%lld\n", ans);
	return 0;
}