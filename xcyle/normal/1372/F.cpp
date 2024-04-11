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
int n, a[maxn];
void solve(int l, int r, int x, int tim)
{
	if(l > r) return;
	if(tim == r - l + 1)
	{
		ru(i, l, r) a[i] = x;
		return;
	}
	int L = mid, R = mid + 1;
	if(tim * 2 >= r - l + 1)
	{
		printf("? %d %d\n", l, mid); fflush(stdout);
		int xL = read(), timL = read();
		if(xL == x) L = mid - timL + 1;
		else 
		{
			printf("? %d %d\n", mid + 1, r); fflush(stdout);
			int xr = read(), timr = read();
			L = mid + timr - tim + 1;
		}
		R = L + tim - 1;
		ru(i, L, R) a[i] = x;
		L--, R++;
	}
	if(l <= L)
	{
		printf("? %d %d\n", l, L); fflush(stdout);
		int xl = read(), timl = read();
		solve(l, L, xl, timl);
	}
	if(R <= r)
	{
		printf("? %d %d\n", R, r); fflush(stdout);
		int xr = read(), timr = read();
		solve(R, r, xr, timr);
	}
}
int main()
{
	n = read();
	printf("? %d %d\n", 1, n); fflush(stdout);
	int x = read(), tim = read();
	solve(1, n, x, tim);
	printf("! "); ru(i, 1, n) printf("%d ", a[i]); fflush(stdout);
	return 0;
}