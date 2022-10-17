#include <bits/stdc++.h>
using namespace std;
int n, q, c;
int a[11][101][101];
int main() {
	scanf("%d%d%d", &n, &q, &c);
	for (int i = 0; i < n; i++) {
		int x, y, s;
		scanf("%d%d%d", &x, &y, &s);
		a[s][x][y]++;
	}
	for (int k = 0; k <= 10; k++) {
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				a[k][i][j] += a[k][i - 1][j] + a[k][i][j - 1] - a[k][i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int t, x1, x2, y1, y2;
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		int z = 0;
		for (int j = 0; j <= c; j++) {
			z += (j + t) % (c + 1) * (a[j][x2][y2] - a[j][x1][y2] - a[j][x2][y1] + a[j][x1][y1]);
		}
		printf("%d\n", z);
	}
	return 0;
}