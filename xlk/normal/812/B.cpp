#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[20][2000];
int l[20], r[20];
int f[20], g[20];
int main() {
	int shabi = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		r[i] = 0;
		l[i] = m + 1;
		for (int j = 0; j < m + 2; j++) {
			scanf("%1d", &a[i][j]);
			if (a[i][j] > 0) {
				l[i] = min(l[i], j);
				r[i] = max(r[i], j);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		if (r[i] != 0 || l[i] != m + 1) {
			shabi = i;
			break;
		}
	}
	f[n - 1] = 0;
	g[n - 1] = m + 1;
	for (int i = n - 2; i >= shabi; i--) {
		f[i] = min(f[i + 1] + 2 * r[i + 1], g[i + 1] + m + 1) + 1;
		g[i] = min(g[i + 1] + 2 * (m + 1 - l[i + 1]), f[i + 1] + m + 1) + 1;
	}
	printf("%d\n", min(f[shabi] + r[shabi], g[shabi] + m + 1 - l[shabi]));
	return 0;
}