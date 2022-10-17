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
int n, m, a[maxn];
inline int calc(int a, int b)
{
	int mn = b - a;
	int mx = min(a, (b - 1) / 2);
	return max(0, mx - mn + 1);
}
int main()
{
	n = read(), m = read();
	ll tot = 0;
	ru(i, 1, n) tot += (i - 1) / 2;
	if(m > tot) {printf("-1\n"); return 0;}
	m = tot - m;
	rd(i, n, 1)
	{
		int x = i;
		while(m && x <= 2 * i)
		{
			m -= calc(i - 1, x);
			m += calc(i - 1, ++x); 
		}
		if(x > 2 * i) a[i] = 1e8 + i * 10000;
		else a[i] = x;
	}
	ru(i, 1, n) printf("%d ", a[i]);
	return 0;
}