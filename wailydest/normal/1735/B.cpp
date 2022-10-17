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
			if (i && a[i] > a[0] * 2 - 1) ans += (a[i] - 1) / (a[0] * 2 - 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}