#include <cstdio>

int t, n, B, x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &B, &x, &y);
		long long ans = 0;
		int pr = 0;
		for (int i = 1; i <= n; ++i) {
			if (pr + x <= B) pr += x;
			else pr -= y;
			ans += pr;
		}
		printf("%lld\n", ans);
	}
	return 0;
}