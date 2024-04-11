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
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
ll a[1000005]; int tot;
int main() {
	n = read();
	for (int i = 1; i * i <= n; i++) if(n % i == 0) {
		a[++tot] = (ll)i * (n / i) * (n / i - 1) / 2 + n / i;
		a[++tot] = (ll)(n / i) * (i) * (i - 1) / 2 + i;
	}
	sort(a + 1, a + tot + 1);
	tot = unique(a + 1, a + tot + 1) - a - 1;
	ru(i, 1, tot) {
		printf("%lld ", a[i]);
	}
	return 0;
}