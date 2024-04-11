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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
ll a[maxn];
int p[maxn], tot;
int main()
{
	n = read();
	ru(i, 1, n) a[i] = read() + a[i - 1];
	ll tmp = a[n];
	ru(i, 2, 1000000) if(tmp % i == 0)
	{
		p[++tot] = i;
		while(tmp % i == 0) tmp /= i;
	}
	if(tmp > 1) p[++tot] = tmp;
	if(!tot) {printf("-1\n"); return 0;}
	ll ans = 1e18;
	ru(i, 1, tot)
	{
		ll res = 0;
		ru(j, 1, n) res += min(a[j] % p[i], p[i] - a[j] % p[i]);
		ans = min(ans, res);
	}
	printf("%lld", ans);
	return 0;
}