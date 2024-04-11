#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long
inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 5050;
int n, t[MAXN], pos[MAXN];
bool f[MAXN][MAXN]; int g[MAXN];

signed main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++)
		t[i] = read(), pos[i] = read(), g[i] = 1e18;
	f[0][0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) if (abs(pos[i] - pos[i - 1]) + t[i - 1] <= t[i]) f[i][j] |= f[i - 1][j];
		if (g[i - 1] <= t[i - 1]) {
			for (j = i + 1; j <= n; j++) if (max(t[i - 1], abs(pos[i - 1] - pos[j]) + g[i - 1]) + abs(pos[j] - pos[i]) <= t[i])
				f[i][j] = 1;
			g[i] = min(g[i], max(g[i - 1] + abs(pos[i] - pos[i - 1]), t[i - 1]));
		}
		if (f[i - 1][i]) {
			for (j = i + 2; j <= n; j++) if (max(t[i], abs(pos[i - 1] - pos[j]) + t[i - 1]) + abs(pos[j] - pos[i + 1]) <= t[i + 1])
				f[i + 1][j] = 1;
			g[i + 1] = min(g[i + 1], max(t[i], t[i - 1] + abs(pos[i - 1] - pos[i + 1])));
		}
	}
	if (g[n] <= t[n] || f[n - 1][n]) puts("YES");   
	else puts("NO");
	return 0;
}