#include <cstdio>

const int N = 100;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			int cur = 0;
			for (int j = i; j >= 0; --j) {
				cur += 1 + !a[j];
				ans += cur;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}