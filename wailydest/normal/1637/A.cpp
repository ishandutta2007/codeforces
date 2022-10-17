#include <cstdio>

const int N = 10000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (i && a[i] < a[i - 1]) ok = 0;
		}
		printf("%s\n", ok ? "NO" : "YES");
	}
	return 0;
}