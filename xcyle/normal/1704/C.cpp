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
#define int long long
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, a[1000005], b[maxn];
void solve()
{
	n = read(), m = read();
	ru(i, 1, m)
	{
		a[i] = read();
	}
	sort(a + 1, a + m + 1);
	ru(i, 1, m - 1) b[i] = a[i + 1] - a[i] - 1;
	b[m] = a[1] - a[m] + n - 1;
	sort(b + 1, b + m + 1);
	int now = 0, ans = m;
	rd(i, m, 1) if(b[i] > 0)
	{
//		printf("%lld ", b[i]);
		int bef = b[i];
		b[i] -= 2 * now;
		if(b[i] == 1 || b[i] == 2) b[i] = 1, now++;
		else if(b[i] > 2) b[i]--, now += 2;
		b[i] = max(b[i], 0ll);
		ans += bef - b[i];
	}
	printf("%lld\n", ans);
}
signed main()
{
	int T = read();
	while(T--) solve();
	return 0;
}