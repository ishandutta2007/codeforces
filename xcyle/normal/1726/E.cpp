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
#define maxn 300005
using namespace std;
const int mo = 998244353;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
int f[maxn], g[maxn];
int fac[maxn], inv[maxn], ifac[maxn];
int calc(int x, int y) {
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
void solve() {
	n = read();
	g[0] = 1;
	ru(i, 1, n) g[i] = (g[i - 1] + (ll)(i - 1) * g[i - 2] % mo) % mo;
	f[0] = 1;
	for (int i = 2; i <= n / 2; i += 2) f[i] = (ll)f[i - 2] * (i - 1) % mo * 2 % mo;
	int ans = 0;
	for (int i = 0; i <= n / 2; i += 2) {
		ans = (ans + (ll)calc(n - i, i) * f[i] % mo * g[n - 2 * i] % mo) % mo;
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