#include <bits/stdc++.h>

const int N = 500;

int a[N + 5][N + 5], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i][i]);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i + 1; j++) if (a[j + i - 1][j] == i) {
			for (int p = 1; p < j; p++) a[p + i][p] = a[p + i - 1][p];
			for (int p = j; p <= n - i; p++) a[p + i][p] = a[p + i][p + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
}