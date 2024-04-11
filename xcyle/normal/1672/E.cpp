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
#define rd(i, l, r) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
inline int que(int x)
{
	printf("? %d\n", x); fflush(stdout);
	return read();
}
int main()
{
	int n = read();
	int l = 1, r = 1e7, md;
	while(l < r)
	{
		md = (l + r) >> 1;
		if(que(md) == 1) r = md;
		else l = md + 1;
	}
	int ans = l, sum = l;
	for (int i = 2; i <= n; i++)
	{
		int x = (sum - 1) / i;
		if(que(x) == i) ans = min(ans, i * x);
	}
	printf("! %d\n", ans); fflush(stdout);
	return 0;
}