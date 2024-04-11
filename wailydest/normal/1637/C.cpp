#include <cstdio>

int t, n, x;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long sum = 0;
		int odd = 0, one = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			if (i && i + 1 < n) {
				odd += x & 1;
				one += x == 1;
				sum += x;
			}
		}
		if (one == n - 2 || odd == 1 && n == 3) printf("-1\n");
		else printf("%lld\n", sum + odd >> 1);
	}
	return 0;
}