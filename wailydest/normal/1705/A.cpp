#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n, x, a[N * 2];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		for (int i = 0; i < 2 * n; ++i) scanf("%d", a + i);
		std::sort(a, a + 2 * n);
		bool ok = 1;
		for (int i = 0; i < n; ++i) if (a[i] + x > a[n + i]) ok = 0;
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}