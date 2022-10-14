#include <stdio.h>

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int n;

		scanf("%d", &n);
		printf("%d 1 1 1\n", n - 3);
	}
	return 0;
}