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
#define maxn 1000005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int a, b, c, d;
int main()
{
	a = read(), b = read(), c = read(), d = read();
	if(!c && !d && a == b + 1)
	{
		printf("YES\n");
		printf("0 ");
		ru(i, 1, b) printf("1 0 ");
		return 0; 
	}
	if(!a && !b && d == c + 1)
	{
		printf("YES\n");
		printf("3 ");
		ru(i, 1, c) printf("2 3 ");
		return 0; 
	}
	if(a > b || d > c) {printf("NO\n"); return 0;}
	b -= a, c -= d;
	if(abs(b - c) > 1) {printf("NO\n"); return 0;}
	printf("YES\n");
	if(b == c)
	{
		ru(i, 1, a) printf("0 1 ");
		ru(i, 1, b) printf("2 1 ");
		ru(i, 1, d) printf("2 3 ");
	}
	if(b == c + 1)
	{
		ru(i, 1, d) printf("3 2 ");
		ru(i, 1, c) printf("1 2 ");
		ru(i, 1, a) printf("1 0 ");
		printf("1 ");
	}
	if(c == b + 1)
	{
		ru(i, 1, a) printf("0 1 ");
		ru(i, 1, b) printf("2 1 ");
		ru(i, 1, d) printf("2 3 ");
		printf("2 ");
	}
	return 0;
}