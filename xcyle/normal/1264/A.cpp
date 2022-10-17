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
#define maxn 400005
#define NO {printf("0 0 0\n"); return;}
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, p[maxn];
void solve()
{
	n = read();
	ru(i, 1, n) p[i] = read();
	int g = 0, s = 0;
	ru(i, 2, n) if(p[i - 1] != p[i]) {g = i - 1; break;}
	if(!g) NO;
	ru(i, 2 * g + 2, n) if(p[i - 1] != p[i]) {s = i - 1; break;}
	if(!s) NO;
	rd(i, n / 2 + 1, g + s + 2)
	{
		if(p[i] != p[i - 1]) {printf("%d %d %d\n", g, s - g, i - 1 - s); return;}
	}
	NO;
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}