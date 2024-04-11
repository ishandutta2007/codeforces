#include <cstdio>

int t, n, k;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		if (k * 2 - 1 > n) printf("-1\n");
		else {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == j && i & 1 ^ 1 && k) {
						printf("R");
						--k;
					} else printf(".");
				}
				printf("\n");
			}
		}
	}
	return 0;
}