#include <cstdio>

const int N = 1005;
int t, n, a[N][N], b[N][N], di1[N][N], di2[N][N];

int solve(int x, int y, int n, bool di) 
{
	if (!n) return 0;
	int res = 0;
	for (int i = 1; i < n; ++i) {
		a[x + i][y + 1] = a[x + i + 1][y] ^ di1[x + n][y + n - i] ^ di1[x + i][y];
		a[x + 1][y + i] = a[x][y + i + 1] ^ di1[x + n - i][y + n] ^ di1[x][y + i];
		if (di && i == 1) res ^= a[x + i][y + 1];
		if (!di) {
			res ^= a[x + i][y + 1];
			if (i > 1) res ^= a[x + 1][y + i];
		}
	}
	return res ^ solve(x + 1, y + 1, n - 2, di);
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
			scanf("%d", a[i] + j);
			b[i][n - j + 1] = a[i][j];
			di1[i][j] = a[i][j] ^ di1[i - 1][j - 1];
			di2[i][j] = a[i][j] ^ di2[i - 1][j + 1];
		}
		int ans = solve(0, 0, n, 0);
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) a[i][j] = di1[i][j] = di2[i][j] = 0;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
			a[i][j] = b[i][j];
			di1[i][j] = a[i][j] ^ di1[i - 1][j - 1];
			di2[i][j] = a[i][j] ^ di2[i - 1][j + 1];
		}
		printf("%d\n", ans ^ solve(0, 0, n, 1));
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) a[i][j] = di1[i][j] = di2[i][j] = 0;
	}
	return 0;
}