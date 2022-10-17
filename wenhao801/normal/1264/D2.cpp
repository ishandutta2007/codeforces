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
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 1001000, mod = 998244353;
int qpow (int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int fac[MAXN], ifac[MAXN];
inline int binom (int x, int y) { if (x < 0 || y < 0 || x < y) return 0; return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod; }

char a[MAXN];

int main () {
	scanf("%s", a + 1); int n = strlen(a + 1);
	int i, j; fac[0] = ifac[0] = 1;
	for (i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
	ifac[n] = inv(fac[n]); for (i = n - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	int A = 0, B = 0, C = 0, D = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] == ')') ++C;
		if (a[i] == '?') ++D;
	}
	int ans = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] == '(') ++A;
		if (a[i] == ')') --C;
		if (a[i] == '?') ++B, --D;
		ans = (ans + 1ll * B * binom(B + D - 1, D + C - A - 1)) % mod;
		ans = (ans + 1ll * A * binom(B + D, D - A + C)) % mod;
	}
	printf("%d\n", ans);
	return 0;
}