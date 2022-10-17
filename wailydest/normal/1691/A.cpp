#include <cstdio>
#include <algorithm>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int s = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			s += x & 1;
		}
		printf("%d\n", std::min(s, n - s));
	}
	return 0;
}