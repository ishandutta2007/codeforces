#include <cstdio>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", (n / 2) * 2 + n + (n / 3) * 2);
	}
	return 0;
}