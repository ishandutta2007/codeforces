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

#define ll long long
const int MAXN = 4040;
int n, m, a[MAXN], siz[MAXN]; ll f[MAXN][MAXN], tmp[MAXN];
void dfs (int x, int l, int r, int w) {
	f[x][0] = f[x][1] = 0; siz[x] = 1;
	int ls = x - 1, rs = x + 1, i, j;
	for (i = x - 1; i >= l; i--) if (a[i] < a[ls]) ls = i;
	for (i = x + 1; i <= r; i++) if (a[i] < a[rs]) rs = i;
	if (ls >= l) {
		dfs(ls, l, x - 1, a[ls] - a[x]);
		for (i = 0; i <= m; i++) tmp[i] = -1;
		for (i = 0; i <= siz[x]; i++) for (j = 0; j <= siz[ls]; j++) if (f[x][i] != -1 && f[ls][j] != -1)
			tmp[i + j] = max(tmp[i + j], f[x][i] + f[ls][j]);
		siz[x] += siz[ls]; for (i = 0; i <= siz[x]; i++) f[x][i] = tmp[i];
	}
	if (rs <= r) {
		dfs(rs, x + 1, r, a[rs] - a[x]);
		for (i = 0; i <= m; i++) tmp[i] = -1;
		for (i = 0; i <= siz[x]; i++) for (j = 0; j <= siz[rs]; j++) if (f[x][i] != -1 && f[rs][j] != -1)
			tmp[i + j] = max(tmp[i + j], f[x][i] + f[rs][j]);
		siz[x] += siz[rs]; for (i = 0; i <= siz[x]; i++) f[x][i] = tmp[i];
	}
	for (i = 0; i <= m; i++) if (f[x][i] != -1) f[x][i] += 1ll * i * (m - i) * w;
}

int main () {
	n = read(), m = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n; i++) for (j = 0; j <= m; j++) f[i][j] = -1;
	for (i = 1, j = 1; i <= n; i++) if (a[i] < a[j]) j = i;
	dfs(j, 1, n, 0); printf("%lld\n", f[j][m]);
	return 0;
}