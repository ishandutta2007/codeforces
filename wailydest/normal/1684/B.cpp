#include <cstdio>

int t, a, b, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a, &b, &c);
		int x = a;
		x = c - c % b + a % b + b;
		printf("%d %d %d\n", x, b, c);
	}
	return 0;
}