#include <cstdio>
#include <algorithm>

const int N = 1005;
int t, n, m, a[N * 2][N * 2], cnt;
char s[N];

bool test(int x1, int y1, int x2, int y2) {
	x1 = std::max(1, x1);
	y1 = std::max(1, y1);
	x2 = std::min(x2, n + m);
	y2 = std::min(y2, n + m);
	--x1;
	--y1;
	return a[x2][y2] - a[x2][y1] - a[x1][y2] + a[x1][y1] == cnt;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n + m; ++i) for (int j = 0; j <= n + m; ++j) a[i][j] = 0;
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			for (int j = 0; j < m; ++j) if (s[j] == 'B') {
				++a[i + j + 1][i + m - j];
				++cnt;
			}
		}
		for (int i = 1; i <= n + m; ++i) for (int j = 1; j <= n + m; ++j) a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		int ans = ~(1 << 31), ii, jj;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			int l = 0, r = n + m, x = i + j + 1, y = i + m - j;
			while (l < r) {
				int m = l + r >> 1;
				if (test(x - m, y - m, x + m, y + m)) r = m;
				else l = m + 1;
			}
			if (r < ans) {
				ans = r;
				ii = i;
				jj = j;
			}
		}
		printf("%d %d\n", ii + 1, jj + 1);
	}
	return 0;
}