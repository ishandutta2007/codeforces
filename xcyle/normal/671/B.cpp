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
int n;
ll a[maxn], k, sum;
int main()
{
	n = read(), k = read();
	ru(i, 1, n) a[i] = read(), sum += a[i];
	sort(a + 1, a + n + 1);
	ll tmp = k, l = a[n], r = a[1];
	ru(i, 1, n - 1)
	{
		if(i * (a[i + 1] - a[i]) <= tmp) tmp -= i * (a[i + 1] - a[i]);
		else {l = a[i] + tmp / i; break;}
	}
	tmp = k;
	rd(i, n, 2)
	{
		if((n - i + 1) * (a[i] - a[i - 1]) <= tmp) tmp -= (n - i + 1) * (a[i] - a[i - 1]);
		else {r = a[i] - tmp / (n - i + 1); break;}
	}
	if(l >= r)
	{
		if(sum % n == 0) printf("0\n");
		else printf("1\n");
	}
	else printf("%lld\n", r - l);
	return 0;
}