#include<stdio.h>
long double E[60][5010];
int f[51], s[51], p[51];
int n, r;
long double E0;
long double min(long double a, long double b) { return a > b ? b : a; }
long double getE(int x, int t) {
	if (E[x][t] != -1) return E[x][t];
	if (t > r) return E[x][t] = E0;
	if (x == n + 1) return 0;
	E[x][t] = p[x + 1] / 100. * (f[x + 1] + min(E0, getE(x + 1, t + f[x + 1])))
		+ (100 - p[x + 1]) / 100. * (s[x + 1] + min(E0, getE(x + 1, t + s[x + 1])));
	return E[x][t];
}
const long double EPS = 1e-10;
int main() {
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", f + i, s + i, p + i);
	}
	long double x = 0, y = 500000000000000;
	while (x + EPS < y && (y - x) / x > EPS) {
		double m = (x + y) / 2;
		E0 = m;
		for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= n * 100 + 5; j++)E[i][j] = -1;
		if (getE(0, 0) >= E0) x = m;
		else y = m;
	}
	printf("%.15lf\n", (double)x);
	return 0;
}