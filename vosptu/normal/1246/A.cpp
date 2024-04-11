#include <bits/stdc++.h>

int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= 100; i++) {
		n -= p;
		if (n < 0)
			break;
		if (__builtin_popcount(n) <= i && i <= n) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
}