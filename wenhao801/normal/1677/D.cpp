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
int n, K, a[MAXN];

int main () {
	int T = read();
	while (T--) {
		n = read(), K = read(); int i, j;
		for (i = 1; i <= n; i++) a[i] = read();
		int ans = 1;
		for (i = n; i >= n - K + 1; i--) if (a[i] > 0) ans = 0;
		for (i = 1; i <= K; i++) ans = 1ll * ans * i % mod;
		for (i = n; i > K; i--) {
			if (a[i - K] > 0) {
				if (a[i - K] + K >= i) ans = 0;
			}
			else if (a[i - K] == 0) ans = 1ll * ans * (min(K, i - 1) + 1) % mod;
			else if (a[i - K] == -1) ans = 1ll * ans * i % mod;
		}
		printf("%d\n", (ans + mod) % mod);
	}
	return 0;
}