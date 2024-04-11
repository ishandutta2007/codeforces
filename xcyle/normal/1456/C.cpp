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
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
ll c[maxn];
ll suf[maxn], sum[maxn];
int main()
{
	int n = read(), k = read() + 1;
	ru(i, 1, n) scanf("%lld", &c[i]);
	sort(c + 1, c + n + 1);
	rd(i, n, 1) sum[i] = sum[i + 1] + c[i], suf[i] = suf[i + 1] + sum[i + 1];
	ll now = 0, ans = suf[1];
	ru(i, 1, n)
	{
		now += c[i] * ((i - 1) / k);
		ans = max(ans, now + suf[i + 1] + ((i + k - 1) / k) * sum[i + 1]);
	}
	printf("%lld\n", ans);
	return 0;
}