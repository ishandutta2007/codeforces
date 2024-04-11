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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, k, a[maxn];
void solve()
{
	n = read(), m = read(), k = read();
	ru(i, 1, k) a[i] = read();
	sort(a + 1, a + k + 1);
	ll now = 0;
	rd(i, k, 1) if(a[i] >= 2 * m) now += a[i] / m;
	if(now >= n && (n % 2 == 0 || a[k] >= 3 * m)) {printf("Yes\n"); return;}
	now = 0;
	rd(i, k, 1) if(a[i] >= 2 * n) now += a[i] / n;
	if(now >= m && (m % 2 == 0 || a[k] >= 3 * n)) {printf("Yes\n"); return;}
	printf("No\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}