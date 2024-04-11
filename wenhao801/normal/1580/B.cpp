#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n, m, K, mod;
int f[110][110][110]; bool vis[110][110][110];
int binom[220][220], fac[220];

int solve (int x, int y, int z) {
	if (!x) return !z;
	if (y == 1) return z == 1 ? fac[x] : 0;
	if (vis[x][y][z]) return f[x][y][z];
	vis[x][y][z] = 1;
	for (int i = 0; i < x; i++) for (int j = 0; j <= z; j++) {
		if (j && i < y - 1) continue;
		if (j != z && x - 1 - i < y - 1) continue;
		f[x][y][z] = (f[x][y][z] + 1ll * binom[x - 1][i] * solve(i, y - 1, j) % mod * solve(x - 1 - i, y - 1, z - j)) % mod;
	}
	return f[x][y][z];
}

int main () {
	n = read(), m = read(), K = read(), mod = read();
	binom[0][0] = fac[0] = 1; int i, j;
	for (i = 1; i <= n; i++) {
		binom[i][0] = 1; fac[i] = 1ll * fac[i - 1] * i % mod;
		for (j = 1; j <= i; j++) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
	}
	printf("%d\n", (solve(n, m, K) + mod) % mod);
	return 0;
}