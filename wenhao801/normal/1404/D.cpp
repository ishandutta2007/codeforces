#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 1001000;
int a[MAXN][2], b[MAXN][2]; bool out[MAXN], vis[MAXN];

int main () {
	int n = read(), i, j;
	if (n % 2 == 0) {
		puts("First");
		for (i = 0; i < 2 * n; i++) printf("%d ", i % n + 1);
		puts(""); fflush(stdout);
		return 0;
	}
	puts("Second"); fflush(stdout);
	for (i = 1; i <= n * 2; i++) {
		int x = read();
		if (a[x][0]) a[x][1] = i; else a[x][0] = i;
	}
	for (i = 1; i <= n; i++) {
		int u = a[i][0] % n, v = a[i][1] % n;
		if (b[u][0]) b[u][1] = i; else b[u][0] = i;
		if (b[v][0]) b[v][1] = i; else b[v][0] = i;
	}
	for (i = 0; i < n; i++) if (!vis[i]) {
		int now = i, pos = b[i][0];
		do {
			out[pos] = a[pos][1] % n == now; vis[now] = 1;
			now = a[pos][0] % n + a[pos][1] % n - now; pos = b[now][0] + b[now][1] - pos;
		} while (now != i);
	}
	int s = 0; for (i = 1; i <= n; i++) s = (s + a[i][out[i]]) % (n << 1);
	s = bool(s); for (i = 1; i <= n; i++) printf("%d ", a[i][out[i] ^ s]); puts("");
	fflush(stdout);
	return 0;
}