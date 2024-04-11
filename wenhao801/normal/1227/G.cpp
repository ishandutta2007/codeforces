#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 1 << 10, base = 998244353, mod = 1e9 + 9;
int n, a[MAXN], now[MAXN];

map <int, int> buc;
bool ans[MAXN][MAXN];

int main () {
	n = read(); int i, j, k;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n; i++) {
		buc.clear();
		for (j = 1; j <= n + 1; j++) {
			if (buc.count(now[j])) {
				int u = buc[now[j]], v = j; --a[i]; ans[u][i] = 1;
				now[u] = (1ll * now[u] * base + 1) % mod; now[v] = 1ll * now[v] * base % mod;
				for (k = 1; k <= n + 1; k++) if (k != u && k != v) {
					now[k] = 1ll * now[k] * base % mod;
					if (a[i]) --a[i], now[k] = (now[k] + 1) % mod, ans[k][i] = 1;
				}
				break;
			}
			else buc[now[j]] = j;
		}
		if (j > n + 1) {
			for (k = 1; k <= n + 1; k++) {
				now[k] = 1ll * now[k] * base % mod;
				if (a[i]) --a[i], now[k] = (now[k] + 1) % mod, ans[k][i] = 1;
			}
		}
	}
	for (i = 1, j = 0; i <= n + 1; i++) if (now[i]) ++j;
	printf("%d\n", j);
	for (i = 1; i <= n + 1; i++) if (now[i]) { for (j = 1; j <= n; j++) putchar('0' + ans[i][j]); puts(""); }
	return 0;
}