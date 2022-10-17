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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 2005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, k, s[maxn][maxn];
void init()
{
	s[0][0] = 1;
	ru(i, 1, maxn - 1) ru(j, 1, i) s[i][j] = (s[i - 1][j - 1] + (ll)s[i - 1][j] * j % mo) % mo; 
}
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
void solve()
{
	n = read(), m = read(), k = read();
	int a = (m + 1) / 2, b = m / 2;
	int temp = (ll)qpow(a + b, mo - 2) * a % mo;
	int ans = 0, now = 1;
	ru(j, 0, min(n, k))
	{
		ans = (ans + (ll)s[k][j] * now % mo) % mo;
		now = (ll)now * temp % mo * (n - j) % mo;
	}
	printf("%d\n", (ll)ans * qpow(a + b, n) % mo);
}
int main()
{
	init();
	int T = read();
	while(T--) solve();
	return 0;
}