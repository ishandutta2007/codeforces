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
int n, a[2005];
inline int gcd(int x, int y) {return !y ? x : gcd(y, x % y);}
int main()
{
	n = read();
	int cnt = 0;
	ru(i, 1, n) a[i] = read(), cnt += (a[i] == 1);
	if(cnt) {printf("%d\n", n - cnt); return 0;}
	int len = n + 1;
	ru(i, 1, n)
	{
		int d = a[i];
		ru(j, i + 1, n)
		{
			d = gcd(d, a[j]);
			if(d == 1) len = min(len, j - i);
		}
	}
	if(len == n + 1) {printf("-1\n"); return 0;}
	printf("%d\n", n - 1 + len);
	return 0;
}