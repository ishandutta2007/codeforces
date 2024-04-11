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
int n, fac[maxn], inv[maxn], ifac[maxn];
map<ll, int> buc;
inline int calc(int x, int y) {
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
void solve() {
	n = read(); buc.clear();
	ll sum = 0;
	ru(i, 1, n) {
		sum += read();
		if(i < n) buc[sum]++;
	}
	int ans = 1;
	for (auto x: buc) if(x.fi * 2 < sum) {
		int a = x.se, b = buc[sum - x.fi];
		int res = 0;
		ru(j, 0, min(a, b)) {
			res = (res + (ll)calc(a, j) * calc(b, j) % mo) % mo;
		}
		ans = (ll)ans * res % mo;
	}
	if(sum % 2 == 0) {
//		printf("%d %d\n", buc[sum / 2], ans); 
		ru(j, 1, buc[sum / 2]) {
			ans = (ll)ans * 2 % mo;
		}
	}
	printf("%d\n", ans);
}
int main() {
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	ru(i, 2, maxn - 1) {
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	int T = read();
	while(T--) solve();
	return 0;
}