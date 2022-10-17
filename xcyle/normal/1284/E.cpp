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
#define lb long double
#define maxn 2505
using namespace std;
const lb pi = acos(-1.0L);
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, x[maxn], y[maxn];
lb tmp[maxn];
inline ll calc(int x)
{
	return (ll)x * (x - 1) * (x - 2) / 6;
}
int main()
{
	n = read();
	ru(i, 1, n) x[i] = read(), y[i] = read();
	ll ans = 0;
	ru(i, 1, n)
	{
		int tot = 0;
		ru(j, 1, n) if(j ^ i) tmp[++tot] = atan2((lb)y[j] - y[i], (lb)x[j] - x[i]);
		sort(tmp + 1, tmp + n);
		int now = 1;
		ru(j, 1, n - 1)
		{
			while(tmp[j] - tmp[now] > pi) now++;
			ans += calc(j - 1);
			if(tmp[j] - tmp[n - 1] + pi > 0) ans -= calc(j - now);
		}
		now = 1;
		ru(j, 1, n - 1)
		{
			while(tmp[j] - tmp[now] + pi > 0 && now < n) now++;
			if(now >= n) break;
			ans -= calc(n - 1 - now + j);
		}
	}
	printf("%lld\n", ans);
	return 0;
}