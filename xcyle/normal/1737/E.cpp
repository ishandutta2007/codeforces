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
#define mid ((l + r + 1) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 1000005
using namespace std;
const int mo = 1e9 + 7;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, f[maxn], g[maxn], pw[maxn], sum[maxn];
inline void upd(int &x, int y) {
	x += y; if(x >= mo) x -= mo;
}
inline int qpow(int x, int step) {
	int res = 1;
	for (; step; step >>= 1) {
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
void solve() {
	n = read();
	f[n] = sum[n] = 2;
	rd(i, n - 1, 1) {
		f[i] = sum[i + 1];
		if(2 * i - 1 < n) upd(f[i], mo - sum[2 * i]);
		sum[i] = (sum[i + 1] + f[i]) % mo;
	}
	int tmp = qpow((mo + 1) / 2, n);
	pw[0] = 1; ru(i, 1, n) pw[i] = (ll)pw[i - 1] * 2 % mo;
	ru(i, 1, n) {
		g[i] = pw[i - (i + 1) / 2];
//		ru(k, (i + 1) / 2, i - 1) {
//			upd(g[i], pw[i - k - 1]);
//		}
	}
	ru(i, 1, n) {
		printf("%d\n", (ll)tmp * f[i] % mo * g[i] % mo);
	}
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}