#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n, m; char a[440][440]; int s[440][440];
int pq;
int sum (int x1, int y1, int x2, int y2) { return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]; }
int tob (int x1, int y1, int x2, int y2) { return (x2 - x1 + 1) * (y2 - y1 + 1) - sum(x1, y1, x2, y2); }
int tow (int x1, int y1, int x2, int y2) { return sum(x1, y1, x2, y2); }

int main () {
	int T = read();
	while (T--) {
		n = read(), m = read(); int i, j, ans = 1e9;
		for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
		for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + a[i][j] - '0';
		for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) s[i][j] += s[i - 1][j];
		for (i = 1; i <= n; i++) for (j = i + 4; j <= n; j++) {
			int cur = 0; pq = (tob(i, 2, i, 3) + tob(j, 2, j, 3) + tob(i + 1, 1, j - 1, 1) + tow(i + 1, 2, j - 1, 3));
			ans = min(ans, pq + tob(i + 1, 4, j - 1, 4));
			for (int k = 5; k <= m; k++) {
				pq += tow(i + 1, k - 1, j - 1, k - 1) + tob(i, k - 1, i, k - 1) + tob(j, k - 1, j, k - 1);
				pq = min(pq, tob(i, k - 2, i, k - 1) + tob(j, k - 2, j, k - 1) + tob(i + 1, k - 3, j - 1, k - 3) + tow(i + 1, k - 2, j - 1, k - 1) - cur);
				ans = min(ans, pq + cur + tob(i + 1, k, j - 1, k));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}