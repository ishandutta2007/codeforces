#include<stdio.h>
int ans[1001];
int C = 0;
int ds(int x) {
	int re = 0;
	while (x) {
		re += x % 10;
		x /= 10;
	}
	return re;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = -1000; i <= 0; i++) {
		if (n + i <= 0) continue;
		if (ds(n + i) + n + i == n) {
			ans[++C] = n + i;
		}
	}
	printf("%d\n", C);
	for (int i = 1; i <= C; i++) printf("%d\n", ans[i]);
	return 0;
}