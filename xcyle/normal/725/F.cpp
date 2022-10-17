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
int n, t[maxn * 2], tot, tot2;
int main()
{
	n = read();
	ll ans = 0;
	ru(i, 1, n)
	{
		int a1 = read(), b1 = read(), a2 = read(), b2 = read();
		if(a1 + b1 >= a2 + b2)
		{
			ans += a1 + a2;
			t[++tot] = a1 + b1, t[++tot] = a2 + b2; 
		}
		else
		{
			int x = a1 - b2, y = b1 - a2;
			if(x <= 0 && y <= 0) continue;
			else if(x <= 0) ans -= y;
			else if(y <= 0) ans += x;
		}
	}
	sort(t + 1, t + tot + 1);
	for (int i = tot - 1; i >= 1; i -= 2) ans -= t[i];
	printf("%lld\n", ans);
	return 0;
}