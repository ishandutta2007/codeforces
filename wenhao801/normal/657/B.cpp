#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 200200, mod = 998244353, inv2 = (mod + 1) >> 1;
const int mod2 = 1004535809, inv2_2 = (mod2 + 1) >> 1;
int qpow (int x, int y, int mod) {
	int ret = 1;
	for (; y; y >>= 1, x = 1ll * x * x % mod) if (y & 1) ret = 1ll * ret * x % mod;
	return ret;
}
int n, m;
int a[MAXN];

using ll = long long;

int main() {
	n = read(), m = read(); int i, j;
	int s = 0, s2 = 0;
	for (i = 0; i <= n; i++) a[i] = read(), s = (s + 1ll * a[i] * qpow(2, i, mod)) % mod, s2 = (s2 + 1ll * a[i] * qpow(2, i, mod2)) % mod2;
	long long ans = 0;
	for (i = 0; i <= n; i++) {
		int cur = -(s - 1ll* a[i] * qpow(2, i, mod)) % mod;
		cur = 1ll * cur * qpow(inv2, i, mod) % mod;
		cur = (cur + mod) % mod;
		int cur2 = -(s2 - 1ll* a[i] * qpow(2, i, mod2))%  mod2;
		cur2 = 1ll * cur2 * qpow(inv2_2, i, mod2) % mod2;
		cur2 = (cur2 + mod2) % mod2;
		for (ll j = -5; j <= 5; j++) for (ll k = -5; k <= 5; k++) {
			if (cur + mod * j == cur2 + mod2 * k && cur + mod * j >= -m && cur + mod * j <= m && !(i == n && cur + mod * j == 0)) ++ans;
		}
	}
	printf("%lld\n", ans);
	return 0;
}