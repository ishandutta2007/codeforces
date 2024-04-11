#include <cstdio>

int t, n, k;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		if (n > k) {
			if (!(n % k)) printf("1\n");
			else printf("2\n");
		}
		else printf("%d\n", (k - 1) / n + 1);
	}
	return 0;
}