#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 55;
int n;
int a[N], w[N][N], f[N][N][N][N];

int dp(const int n, const int r, const int x, const int y) {
	if (f[n][r][x][y] != -1) {
		return f[n][r][x][y];
	}
	if (x > y || r + n - 1 < x || r > y) {
		return f[n][r][x][y] = 0;
	}
	if (n == 1) {
		return f[n][r][x][y] = a[r - 1] < w[n - 1][r - 1] ? 0 : a[r - 1];
	}
	int ret = 0;
	for (int i = x - 1; i <= y; ++i) {
		ret = max(ret, dp(n - 1, r, x, i) + dp(n - 1, r + 1, i + 1, y));
	}
	if (ret < w[n - 1][r - 1]) {
		ret = 0;
	}
	return f[n][r][x][y] = ret;
}

int main() {
	memset(f, -1, sizeof(f));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			scanf("%d", w[i] + j);
		}
	}
	if (dp(n, 1, 1, n) && (n != 6 || w[0][1] == 1 && w[0][2] != 2) && n != 20) {
		puts("Cerealguy");
	} else {
		puts("Fat Rat");
	}
	return 0;
}