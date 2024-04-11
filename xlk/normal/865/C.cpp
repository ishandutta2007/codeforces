#include <bits/stdc++.h>
using namespace std;
int n, r, a[60], b[60];
double p[60], f[60][5020];
double calc(double T) {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= r; j++) {
			if (j + a[i] > r) {
				f[i][j] = T;
			} else if (j + b[i] > r) {
				f[i][j] = (f[i + 1][j + a[i]] + a[i]) * p[i] + (T + b[i]) * (1 - p[i]);
			} else {
				f[i][j] = (f[i + 1][j + a[i]] + a[i]) * p[i] + (f[i + 1][j + b[i]] + b[i]) * (1 - p[i]);
			}
			f[i][j] = min(f[i][j], T);
		}
	}
	return f[0][0];
}
int main() {
	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%lf", &a[i], &b[i], &p[i]);
		p[i] /= 100;
	}
	double L = 0, R = 1e9;
	for (int _ = 0; _ < 100; _++) {
		double M = (L + R) / 2;
		if (calc(M) < M) {
			R = M;
		} else {
			L = M;
		}
	}
	printf("%.12f\n", (L + R) / 2);
	return 0;
}