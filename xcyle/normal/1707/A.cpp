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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, a[100005], ans[100005];
void solve()
{
	n = read(), q = read();
	ru(i, 1, n) ans[i] = 0;
	ru(i, 1, n) a[i] = read();
	int now = 0;
	rd(i, n, 1)
	{
		if(a[i] >= now + 1)
		{
			if(now < q) now++, ans[i] = 1;
		}
		else if(a[i] <= now) ans[i] = 1;
	}
	ru(i, 1, n) printf("%d", ans[i]); printf("\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}