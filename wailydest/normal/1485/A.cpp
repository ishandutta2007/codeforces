#include <cstdio>
#include <algorithm>

int t, a, b;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		int ans = ~(1 << 31);
		for (int i = 0; i <= 100; ++i, ++b) if (b != 1) {
			int a_ = a, x = 0;
			while (a_) {
				++x;
				a_ /= b;
			}
			ans = std::min(ans, x + i);
		}
		printf("%d\n", ans);
	}
	return 0;
}