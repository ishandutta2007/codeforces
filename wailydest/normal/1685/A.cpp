#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, a[N], ans[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		if (n & 1) printf("NO\n");
		else {
			bool done = 0, ok = 1;
			for (int i = 0; i < n;) {
				int amt = 0;
				do {
					++i;
					++amt;
				} while (i < n && a[i] == a[i - 1]);
				if (amt == n / 2) {
					done = 1;
					for (int j = 0, k = 0; j < n; ++j) {
						if (j & 1) ans[j] = a[i - 1];
						else {
							while (a[k] == a[i - 1]) ++k;
							ans[j] = a[k];
							++k;
						}
					}
				} else if (amt > n / 2) {
					ok = 0;
					done = 1;
				}
			}
			for (int i = 0; i < n; ++i) ans[i] = i & 1 ^ 1 ? a[i / 2] : a[n / 2 + i / 2];
			for (int i = 0; i < n; ++i) {
				int pr = (i - 1 + n) % n, next = (i + 1) % n;
				if (!(ans[i] > ans[pr] && ans[i] > ans[next] || ans[i] < ans[pr] && ans[i] < ans[next])) ok = 0;
			}
			if (ok) {
				printf("YES\n");
				for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
				printf("\n");
			} else printf("NO\n");
		}
	}
	return 0;
}