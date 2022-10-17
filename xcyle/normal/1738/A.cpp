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
int n, cnt[2], tp[200005];
int a[2][200005];
void solve() {
	n = read();
	cnt[0] = cnt[1] = 0;
	ru(i, 1, n) tp[i] = read();
	ll ans = 0;
	ru(i, 1, n) {
		int x = read(); ans += x;
		a[tp[i]][++cnt[tp[i]]] = x;
	}
	sort(a[0] + 1, a[0] + cnt[0] + 1, greater<int>());
	sort(a[1] + 1, a[1] + cnt[1] + 1, greater<int>());
	ru(i, 1, min(cnt[0], cnt[1])) {
		ans += a[0][i];
		ans += a[1][i];
	}
	if(cnt[0] == cnt[1]) {
		ans -= min(a[0][cnt[0]], a[1][cnt[1]]);
	}
	printf("%lld\n", ans);
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}