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

const int mod = 1e9 + 7, MAXN = 3030;
int qpow (int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int n, D; vector <int> E[MAXN];
int f[MAXN][MAXN], binom[MAXN][MAXN], g[MAXN];

void dfs (int x, int fa) {
	for (int i = 1; i <= n; i++) f[x][i] = 1;
	for (auto i: E[x]) if (i != fa) {
		dfs(i, x);
		for (int j = 1; j <= n; j++) f[i][j] = (f[i][j - 1] + f[i][j]) % mod;
		for (int j = 1; j <= n; j++) f[x][j] = 1ll * f[i][j] * f[x][j] % mod;
	}
}

int main () {
	n = read(), D = read(); int i, j;
	for (i = 1; i < n; i++) j = read(), E[j].push_back(i + 1), E[i + 1].push_back(j);
	dfs(1, 0); binom[0][0] = 1;
	for (i = 1; i <= n; i++) {
		binom[i][0] = 1;
		for (j = 1; j <= i; j++) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
	}
	for (i = 1; i <= n; i++) for (j = 1; j <= i; j++) g[i] = (g[i] + (((i - j) & 1) ? -1ll : 1ll) * binom[i - 1][j - 1] * f[1][j]) % mod;
	int ans = 0;
	for (i = 1, j = D; i <= n; i++, j = 1ll * j * (D - i + 1) % mod * inv(i) % mod)
		ans = (ans + 1ll * j * g[i]) % mod;
	printf("%d\n", (ans + mod) % mod);
	return 0;
}