#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, k, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			sum += a[i];
			a[i] = -a[i] + n - i - 1;
		}
		std::sort(a, a + n);
		for (int i = 0; i < k; ++i) sum += a[i];
		sum -= (long long)k * (k - 1) / 2;
		printf("%lld\n", sum);
	}
	return 0;
}