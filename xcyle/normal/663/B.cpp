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
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
char s[100005];
int main()
{
	n = read();
	ru(i, 1, n)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int now = 0;
		ll x = 0;
		ru(i, 5, len) x = x * 10 + s[i] - '0', now = now * 10 + 1;
		if(x < 1988 + now)
		{
			int tmp = 1;
			ru(i, 5, len) tmp *= 10;
//			printf("%d %d %d\n", x, tmp, 1988 + now);
			x += ((1988 + now - x + tmp - 1) / tmp) * tmp; 
		}
		printf("%lld\n", x);
	}
	return 0;
}