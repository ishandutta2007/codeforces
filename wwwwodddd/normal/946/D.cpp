#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int f[520][520];
int g[520][520];
char s[520][520];
int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		int c = 0;
		vector<int> p;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') {
				c++;
				p.push_back(j);
			}
		}
		for (int j = 0; j <= l; j++) {
			if (j >= c) {
				g[i][j] = 0;
			} else {
				g[i][j] = m;
				for (int k = 0; k + (c - j) - 1 < c; k++) {
					g[i][j] = min(g[i][j], p[k + (c - j) - 1] - p[k] + 1);
				}
			}
//			printf("%d %d %d\n", i, j, g[i][j]);
		}
	}
	memset(f, 0x3f, sizeof f);
	memset(f[0], 0, sizeof f[0]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= l; j++) {
			for (int k = 0; k <= j; k++) {
				f[i + 1][j] = min(f[i + 1][j], f[i][j - k] + g[i][k]);
			}
		}
	}
	printf("%d\n", f[n][l]);
	return 0;
}