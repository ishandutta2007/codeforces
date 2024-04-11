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
#define maxn 200005
using namespace std;
const int mo = 998244353;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], cnt[maxn * 2][2], fac[maxn], ifac[maxn], inv[maxn];
inline int calc(int x, int y) {
	if(x < y || y < 0) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
int main() {
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	ru(i, 2, maxn - 1) {
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	n = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, n) cnt[a[i]][read()]++;
	int t = 0, ans = 1, tot = 0;
	ru(i, 1, 2 * n) if(cnt[i][0] || cnt[i][1]) {
		if(!t) {
			if(cnt[i][0]) t = i;
			else t = i + n - 1;
		}
		if(t < i) ans = 0;
		if(t == i) {
			ans = (ll)ans * fac[n] % mo * ifac[n - cnt[i][1]] % mo * fac[cnt[i][0]] % mo;
			continue;
		}
		if(cnt[i][0] && tot + i < t) ans = 0;
		ans = (ll)ans * fac[cnt[i][0]] % mo;
		if(cnt[i][1] > 1 || i + n - 1 < t) ans = 0;
		tot += cnt[i][0] + cnt[i][1];
	}
	printf("%d\n", ans);
	return 0;
}