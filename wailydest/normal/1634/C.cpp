#include <cstdio>

int t, n, k;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		if (k == 1 || n & 1 ^ 1) {
			printf("YES\n");
			if (k == 1) for (int i = 1; i <= n; ++i) printf("%d\n", i);
			else {
				for (int i = 0; i < n >> 1; ++i) {
					for (int j = 0; j < k; ++j) printf("%d ", (i * k + j << 1) + 1);
					printf("\n");
				}
				for (int i = 0; i < n >> 1; ++i) {
					for (int j = 0; j < k; ++j) printf("%d ", (i * k + j << 1 | 1) + 1);
					printf("\n");
				}
			}
		} else printf("NO\n");
	}
	return 0;
}