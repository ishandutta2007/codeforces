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
#define maxn 300005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int main()
{
	n = read();
	ru(i, 1, n) a[i] = read(); 
	sort(a + 1, a + n + 1);
	int ans = 0, pw = 1;
	ru(i, 1, n)
	{
		ans = (ans + (ll)pw * a[i] % mo) % mo;
		pw = (ll)pw * 2 % mo;
	}
	pw = 1;
	rd(i, n, 1)
	{
		ans = (ans + mo - (ll)pw * a[i] % mo) % mo;
		pw = (ll)pw * 2 % mo;
	}
	printf("%d\n", ans);
	return 0;
}