#include <cstdio>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int x;
		bool fi = 0;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			if (i + 1 < n) {
				if (x) fi = 1;
				else ans += fi;
				ans += x;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}