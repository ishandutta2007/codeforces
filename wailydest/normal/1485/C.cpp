#include <cstdio>
#include <algorithm>

int t, x, y;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		long long ans = 0;
		for (int i = 1; i * i <= x; ++i) ans += std::min(y + 1, x / i) - std::min(i + 1, std::min(y + 1, x / i));
		printf("%lld\n", ans);
	}
	return 0;
}