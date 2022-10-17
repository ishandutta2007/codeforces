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
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[10000005];
void solve()
{
	int x = read(); scanf("%s", s + 1);
	int n = strlen(s + 1);
	int tp = 0;
	ru(i, 1, x)
	{
		tp |= (n >= x);
		if(tp) n = (n + (ll)(n - i + mo) * (s[i] - '1') % mo) % mo;
		else
		{
			int tmpn = n;
			ru(c, 1, s[i] - '1') ru(j, i + 1, tmpn) s[++n] = s[j];
		}
	}
	printf("%d\n", n);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}