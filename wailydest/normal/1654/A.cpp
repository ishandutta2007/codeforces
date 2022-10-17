#include <cstdio>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int mx = 0, mx1 = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if (x > mx) {
				mx1 = mx;
				mx = x;
			} else if (x > mx1) mx1 = x;
		}
		printf("%d\n", mx + mx1);
	}
	return 0;
}