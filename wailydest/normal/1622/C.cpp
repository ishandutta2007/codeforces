#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, a[N];
long long k;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &k);
		long long res = 0, ans;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			res += a[i];
		}
		ans = res - k;
		std::sort(a, a + n);
		for (int i = n - 1; i > 0; --i) {
			res -= a[i] - a[0];
			ans = std::min(ans, n - i + (res > k ? (res - k - 1) / (n - i + 1) + 1 : 0));
		}
		printf("%lld\n", std::max(ans, (long long)0));
	}
	return 0;
}