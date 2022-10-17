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

const int MAXN = 110;
int n, m, a[MAXN][MAXN];
int out = 1e9 + 7, now;

int main () {
	n = read(), m = read(); int i, j, k;
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) a[i][j] = read();
	int mx = 1e9;
	for (i = 1; i <= m; i++) mx = min(mx, a[1][i]);
	for (i = 0; i <= mx; i++) {
		for (j = 2; j <= n; j++) {
			if (a[j][1] - (a[1][1] - i) < 0) break;
			for (k = 2; k <= m; k++) if (a[j][k] - (a[1][k] - i) != a[j][k - 1] - (a[1][k - 1] - i))
				break;
			if (k <= m) break;
		}
		if (j > n) {
			int ans = (i);
			for (j = 1; j <= m; j++) ans += (a[1][j] - i);
			for (j = 2; j <= n; j++) ans += (a[j][1] - (a[1][1] - i));
			if (ans < out) out = ans, now = i;
		}
	}
	if (out > 1e9) puts("-1");
	else {
		cout << out << endl;
		for (int i = 1; i <= now; i++) puts("row 1");
		for (j = 1; j <= m; j++) {
			for (int k = 1; k <= a[1][j] - now; k++) printf("col %d\n", j);
		}
		for (j = 2; j <= n; j++) for (int k = 1; k <= a[j][1] - (a[1][1] - now); k++) printf("row %d\n", j);
	}
	return 0;
}