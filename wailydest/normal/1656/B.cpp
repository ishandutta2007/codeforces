#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, k, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		bool ok = 0;
		for (int i = 0; i < n; ++i) if (std::binary_search(a, a + n, k + a[i])) ok = 1;
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}