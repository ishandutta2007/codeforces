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
int r, n;
int f[1000005], x[1000005], y[1000005];
void solve()
{
	r = read(), n = read();
	ru(i, 0, 1000000) f[i] = -n;
	x[0] = 1, y[0] = 1, f[0] = 0; 
	int mx = -n, las = 0;
	ru(i, 1, n)
	{
		int T = read(), X = read(), Y = read();
		while(las < T - 2 * r) mx = max(mx, f[las++]);
		x[T] = X, y[T] = Y;
		f[T] = mx + 1;
		ru(j, 1, min(2 * r, T))
		{
			if(abs(x[T] - x[T - j]) + abs(y[T] - y[T - j]) <= j) f[T] = max(f[T], f[T - j] + 1);
		}
	}
	while(las <= 1000000) mx = max(mx, f[las++]);
	printf("%d\n", mx);
}
int main()
{
	solve(); 
	return 0;
}