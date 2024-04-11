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

const int mod = 1e9 + 7, MAXK = 440;
int qpow (int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod; y >>=1;
	}
	return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int s1[MAXK][MAXK], binom[MAXK], f[MAXK][MAXK], B[MAXK][MAXK];

int main () {
	int n = read(), K = read(), i ,j, k;
	s1[0][0] = binom[0] = B[0][0] = 1;
	for (i = 1; i <= K << 1; i++) {
		binom[i] = 1ll * binom[i - 1] * (n - i + 1) % mod * inv(i) % mod;
		s1[i][0] = 0; B[i][0] = 1;
		for (j = 1; j <= i; j++) s1[i][j] = (s1[i - 1][j - 1] + 1ll * (i - 1) * s1[i - 1][j]) % mod, B[i][j] = (B[i - 1][j - 1] + B[i - 1][j]) % mod;
	}
	f[0][0] = 1;
	for (i = 1; i <= min(n, K << 1); i++) for (j = 0; j <= i; j++) {
		for (k = j; k <= i; k++) f[i][j] = (f[i][j] + (((i - k) & 1) ? -1ll : 1ll) * B[i][k] * s1[k][k - j]) % mod;
		if (!j) f[i][0] = 0;
	}
	for (int x = 1; x <= K; x++) {
		int ans = 0;
		for (i = 0; i <= min(n, K << 1); i++) for (j = x & 1; j <= x; j += 2) ans = (ans + 1ll * binom[i] * f[i][j]) % mod;
		printf("%d ", (ans + mod) % mod);
	}
	return 0;
}