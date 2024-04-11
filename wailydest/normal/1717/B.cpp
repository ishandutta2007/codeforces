#include <cstdio>

int t, n, k, r, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &k, &r, &c);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) printf("%c", (i + j) % k == (r + c - 2) % k ? 'X' : '.');
			printf("\n");
		}
	}
	return 0;
}