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

const int mod = 998244353, MAXN = 100100;
int qpow (int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll *ret * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ret;
}

int fac[MAXN], ifac[MAXN];
int binom (int x, int y) { return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod; }

int n; char a[MAXN];

int main () {
	int i, j;
	fac[0] = ifac[0] = 1;
	for (i = 1; i <= 100000; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[100000] = qpow(fac[100000], mod - 2);
	for (i = 100000 - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	int T = read();
	while (T--) {
		n = read(); scanf("%s", a + 1);
		int up = n, down = 0, now = 0; a[n + 1] = '0';
		for (i = 1; i <= n + 1; i++) {
			if (a[i] == '1') ++now;
			else {
				if (now) {
					if (now & 1) --up;
					up -= now >> 1; down += now >> 1;
					now = 0;
				}
			}
		}
		printf("%d\n", binom(up, down));
	}
	return 0;
}