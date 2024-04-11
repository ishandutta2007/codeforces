#include <cstdio>
#include <algorithm>

const int N = 1000;
int n, a[N];

int main() 
{
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i) if (i & 1 ^ 1) {
		long long sum = 0, mn = 0;
		for (int j = i + 1; j < n; ++j) {
			if (j & 1) {
				if (sum >= 0) ans += std::max((long long)0, std::min((long long)a[i], a[j] - sum) - mn);
				else ans += std::max((long long)0, std::min(a[i] - std::max(-sum, mn), (long long)a[j] - std::max((long long)0, mn + sum)));
				sum -= a[j];
			}
			else sum += a[j];
			mn = std::max(mn, -sum - 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}