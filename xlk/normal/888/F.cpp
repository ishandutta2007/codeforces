#include <bits/stdc++.h>
using namespace std;
long long p = 1000000007;
int n, a[520][520], f[520][520], g[520][520];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		f[i][i] = g[i][i] = 1;
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i < n; i++) {
			int j = (i + l - 1) % n;
			if (a[i][j]) {
				for (int k = i; k != j; k = (k + 1) % n) {
					g[i][j] = (g[i][j] + (long long)f[i][k] * f[(k + 1) % n][j]) % p;
				}
			}
			for (int k = i; k != j; k = (k + 1) % n) {
				f[i][j] = (f[i][j] + (long long)f[i][k] * g[k][j]) % p;
			}
		}
	}
	printf("%d\n", f[0][n - 1]);
	return 0;
}