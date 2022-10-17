#include <cstdio>

const int N = 200000;
int t, n, a[N], inc[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			inc[i] = 0;
			scanf("%d", a + i);
			sum += a[i];
		}
		int amt = sum / n, d = 0;
		for (int i = n - 1; i >= 0; --i) {
			bool add = 0;
			if (a[i] + d > 1 || a[i] + d == 1 && !i) {
				a[i] = 1;
				--amt;
			} else {
				add = 1;
				a[i] = 0;
			}
			if (i) ++inc[i - amt + add];
			d += inc[i] - 1;
		}
		for (int i = 0; i < n; ++i) printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}