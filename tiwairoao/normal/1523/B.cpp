#include <bits/stdc++.h>

const int N = 1000;

int a[N + 5], b[N + 5], n;

void print(int i, int j) {
	assert (i < j);
	printf("1 %d %d\n", i, j), a[i] += a[j];
	printf("2 %d %d\n", i, j), a[j] -= a[i];
	printf("2 %d %d\n", i, j), a[j] -= a[i];
	printf("1 %d %d\n", i, j), a[i] += a[j];
	printf("2 %d %d\n", i, j), a[j] -= a[i];
	printf("2 %d %d\n", i, j), a[j] -= a[i];
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	printf("%d\n", 3 * n);
	for (int i = 1, j = n; i < j; i++, j--)
		print(i, j);
	for (int i = 1; i <= n; i++) assert (b[i] + a[i] == 0);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}