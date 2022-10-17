#include <cstdio>
#include <algorithm>
#include <utility>

int t;
std::pair<int, int> s1, s2;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		long long n, k;
		scanf("%lld%lld", &n, &k);
		scanf("%d%d%d%d", &s1.first, &s1.second, &s2.first, &s2.second);
		if (s1.first > s2.first) std::swap(s1, s2);
		long long inter = std::max(0, std::min(s1.second, s2.second) - s2.first);
		if (inter * n >= k) printf("0\n");
		else {
			long long cost = std::max(0, s2.first - s1.second);
			long long to = std::max(s2.second, s1.second) - s1.first;
			long long ans = ~((long long)1 << 63);
			long long before = 0;
			k -= n * inter;
			to -= inter;
			if (!cost) ans = k * 2;
			for (int i = 0; i < n; ++i) {
				if (to >= k) {
					ans = std::min(ans, before + cost + k);
					break;
				}
				k -= to;
				before += cost + to;
				ans = std::min(ans, before + k * 2);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}