#include <cstdio>
#include <algorithm>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n < 100) printf("%d\n", n % 10);
		else {
			int mn = 10;
			while (n) {
				mn = std::min(mn, n % 10);
				n /= 10;
			}
			printf("%d\n", mn);
		}
	}
	return 0;
}