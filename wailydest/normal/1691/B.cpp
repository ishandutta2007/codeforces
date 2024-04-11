#include <cstdio>

const int N = 100000;
int t, n, a[N], p[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		bool ok = 1;
		for (int i = 0; i < n;) {
			int amt = 0;
			do {
				++amt;
				++i;
			} while (i < n && a[i] == a[i - 1]);
			for (int j = i - amt; j < i; ++j) p[j] = j + 2;
			p[i - 1] = i - amt + 1;
			if (amt == 1) ok = 0;
		}
		if (ok) {
			for (int i = 0; i < n; ++i) printf("%d ", p[i]);
			printf("\n");
		} else printf("-1\n");
	}
	return 0;
}