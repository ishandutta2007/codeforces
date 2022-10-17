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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], b[maxn];
int main()
{
	n = read(), k = read();
	ru(i, 0, n) b[i] = a[i] = read();
	ru(i, 0, n - 1)
	{
		a[i + 1] += a[i] / 2;
		a[i] -= (a[i] / 2) * 2;
	}
	int pos = n;
	rd(i, n - 1, 0) if(a[i] != 0) pos = i;
	ll tmp = 0, ans = 0;
	rd(i, n, 0)
	{
		tmp = tmp * 2 + a[i];
		if(i <= pos && abs(tmp - b[i]) <= k && !(i == n && tmp == b[i])) ans++; 
		if(abs(tmp) > k + 1e9) break;
	}
	printf("%lld\n", ans);
	return 0;
}