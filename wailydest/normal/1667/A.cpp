#include <cstdio>
#include <algorithm>

const int N = 5000;
int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	long long ans = ~((long long)1 << 63);
	for (int i = 0; i < n; ++i) {
		long long prev = 0, res = 0;
		for (int j = i - 1; j >= 0; --j) {
			long long k = prev / a[j] + 1;
			res += k;
			prev = k * a[j];
		}
		prev = 0;
		for (int j = i + 1; j < n; ++j) {
			long long k = prev / a[j] + 1;
			res += k;
			prev = k * a[j];
		}
		ans = std::min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}