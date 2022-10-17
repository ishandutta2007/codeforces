#include <cstdio>

int t, n, k;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < 2 * k - n - 1; ++i) printf("%d ", i + 1);
		for (int i = 2 * k - n - 1; i < k; ++i) printf("%d ", k - (i - 2 * k + n) - 1);
		printf("\n");
	}
	return 0;
}