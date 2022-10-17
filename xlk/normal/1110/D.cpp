#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[1000020];
int b[1000020];
int f[10][10];
int g[10][10];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (a[i] >= 6) {
			ans += a[i] / 3;
			a[i] %= 3;
			a[i] += 6;
			ans -= 2;
		}
	}
	memset(f, 0xc0, sizeof f);
	f[0][0] = 0;
	for (int t = 1; t <= m; t++) {
		memcpy(g, f, sizeof f);
		memset(f, 0xc0, sizeof f);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int k = a[t];
				for (int p1 = 0; p1 <= i && p1 <= j && p1 <= k; p1++) {
					for (int p2 = 0; p1 + 3 * p2 <= k; p2++) {
						f[j - p1][k - p1 - 3 * p2] = max(f[j - p1][k - p1 - 3 * p2], g[i][j] + p1 + p2);
					}
				}
			}
		}
	}
	int ans2 = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ans2 = max(ans2, f[i][j]);
		}
	}
	printf("%d\n", ans + ans2);
	return 0;
}