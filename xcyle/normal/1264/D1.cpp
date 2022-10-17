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
int n, fac[maxn], inv[maxn], ifac[maxn];
char s[maxn];
inline int calc(int x, int y)
{
	if(x < y || y < 0) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main()
{
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	ru(i, 2, maxn - 1)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	scanf("%s", s + 1); n = strlen(s + 1);
	int x = 0, y = 0, a = 0, b = 0;
	ru(i, 1, n)
	{
		if(s[i] == ')') b++;
		if(s[i] == '?') y++;
	}
	int ans = 0;
	ru(i, 1, n)
	{
		if(s[i] == ')') b--;
		if(s[i] == '?') y--;
		if(s[i] == '(') a++;
		if(s[i] == '?') x++;
		ans = (ans + ((ll)a * calc(x + y, y - a + b) % mo + (ll)x * calc(x + y - 1, y - a - 1 + b) % mo) % mo) % mo;
	}
	printf("%d\n", ans);
	return 0;
}