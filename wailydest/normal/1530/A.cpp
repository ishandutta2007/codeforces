#include <cstdio>
#include <algorithm>

int t, n;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		while (n) {
			ans = std::max(ans, n % 10);
			n /= 10;
		}
		printf("%d\n", ans);
	}
	return 0;
}