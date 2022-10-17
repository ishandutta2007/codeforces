#include <bits/stdc++.h>
using namespace std;
int n, a[5], b[5], c[5];
char s[10][1020];
int f[1020][257];
void dfs(int i, int x, int w) {
	if (x == 4) {
		for (int i = 0; i < 4; i++) {
			if (c[i] >= 4) {
				return;
			}
		}
		int u = 0;
		for (int i = 0; i < 4; i++) {
			u |= c[i] << (2 * i);
		}
		f[i + 1][u] = min(f[i + 1][u], w);
		return;
	}
	c[x] = b[x];
	dfs(i, x + 1, w);
	if (x < 4 && b[x] <= 1) {
		c[x] = 0;
		dfs(i, x + 1, w + a[1]);
	}
	if (x < 3 && b[x] <= 2 && b[x + 1] <= 2) {
		c[x] = 0;
		c[x + 1] = 0;
		dfs(i, x + 2, w + a[2]);
		dfs(i, x + 1, w + a[2]);
	}
	if (x < 2 && b[x] <= 3 && b[x + 1] <= 3 && b[x + 2] <= 3) {
		c[x] = 0;
		c[x + 1] = 0;
		c[x + 2] = 0;
		dfs(i, x + 3, w + a[3]);
		dfs(i, x + 2, w + a[3]);
		dfs(i, x + 1, w + a[3]);
	}
	if (x < 1 && b[x] <= 4 && b[x + 1] <= 4 && b[x + 2] <= 4 && b[x + 3] <= 4) {
		c[x] = 0;
		c[x + 1] = 0;
		c[x + 2] = 0;
		c[x + 3] = 0;
		dfs(i, x + 4, w + a[4]);
		dfs(i, x + 3, w + a[4]);
		dfs(i, x + 2, w + a[4]);
		dfs(i, x + 1, w + a[4]);
	}
}
int main() {
	scanf("%d%d%d%d%d", &n, &a[1], &a[2], &a[3], &a[4]);
	for (int i = 0; i < 4; i++) {
		scanf("%s", s[i]);
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 256; j++) {
			if (f[i][j] == 0x3f3f3f3f) {
				continue;
			}
			int u = j;
			for (int k = 0; k < 4; k++) {
				b[k] = u % 4;
				u /= 4;
			}
			for (int k = 0; k < 4; k++) {
				if (s[k][i] == '*' || b[k] > 0) {
					b[k]++;
				}
			}
			dfs(i, 0, f[i][j]);
		}
	}
	printf("%d\n", f[n][0]);
	return 0;
}