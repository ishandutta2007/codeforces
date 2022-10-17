#include <cstdio>

const int N = 100000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		bool ok = 1;
		for (int p = 0; p < 2; ++p) {
			int pr = -1;
			for (int i = 0; i < n; ++i) if (a[i] & 1 ^ p ^ 1) {
				if (pr > a[i]) ok = 0;
				pr = a[i];
			}
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}