#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 400400, mod = 998244353;
int qpow (int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

#define pii pair<int, int>
#define fr first
#define se second

int n, m, fac[MAXN], ifac[MAXN]; pii a[MAXN];
namespace BIT {
	int t[MAXN]; vector <pii> v;
	inline int lowbit (int x) { return x & -x; }
	inline int sum (int x) { int ret = 0; while (x) ret = (ret + t[x]) % mod, x -= lowbit(x); return ret; }
	inline void add (int x, int k) { v.push_back(make_pair(x, k)); while (x <= 200000) t[x] = (t[x] + k) % mod, x += lowbit(x); }
	inline void reset () { for (auto i: v) add(i.fr, -i.se); v.clear(); }
	int kth (int k) {
		int pos = 0;
		for (int i = 20; i >= 0; i--) {
			pos += 1 << i;
			if (pos > n || t[pos] >= k) pos -= 1 << i;
			else k -= t[pos];
		}
		return pos + 1;
	}
}

int main () {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= 400000; i++) BIT::add(i, 1), fac[i] = 1ll * i * fac[i - 1] % mod;
	ifac[400000] = inv(fac[400000]); for (int i = 399999; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	BIT::v.clear();
	int T = read();
	while (T--) {
		n = read(), m = read(); int i, j; BIT::reset();
		for (i = 1; i <= m; i++) a[i].fr = read(), a[i].se = read();
		int ans = 1;
		for (i = m; i >= 1; i--) {
			int now = BIT::kth(a[i].se);
			if (BIT::kth(a[i].se + 1) == now + 1) ++ans;
			BIT::add(now, -1);
		}
		printf("%d\n", (1ll * fac[2 * n - ans] * ifac[n] % mod * ifac[n - ans] % mod + mod) % mod);
	}
	return 0;
}