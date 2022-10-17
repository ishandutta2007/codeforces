#include <cstdio>

int t, n, x;
long long y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%lld", &n, &x, &y);
		x ^= y;
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			x ^= v;
		}
		if (x & 1) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}