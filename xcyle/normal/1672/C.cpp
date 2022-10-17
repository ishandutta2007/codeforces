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
#define rd(i, l, r) for (int i = (r); i >= (l); i--)
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
int n, a[maxn], b[maxn];
int cnt[maxn];
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	a[n + 1] = 0;
	int ans = 0, i, j;
	for (i = 1; i <= n && a[i] != a[i + 1]; i++);
	for (j = n; j >= 1 && a[j] != a[j - 1]; j--);
	if((j - i + 1) < 3) printf("0\n");
	else if((j - i + 1) == 3) printf("1\n");
	else printf("%d\n", j - i - 2);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}