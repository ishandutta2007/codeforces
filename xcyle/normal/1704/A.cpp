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
int n, m;
char s[55], t[55];
void solve()
{
	n = read(), m = read();
	scanf("%s%s", s + 1, t + 1);
	ru(i, 2, m)
	{
		if(s[n - m + i] != t[i]) {printf("No\n"); return;}
	}
	int mn = s[n - m + 1] - '0', mx = s[n - m + 1] - '0';
	ru(i, 1, n - m)
	{
		mn = min(mn, s[i] - '0');
		mx = max(mx, s[i] - '0');
	}
	if(mn <= t[1] - '0' && t[1] - '0' <= mx) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}