#include <cstdio>

const int N = 200000;
int t, n, amt[N], a[N], b[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
			amt[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", b + i);
			--b[i];
		}
		bool ok = 1;
		for (int i = n - 1, j = n - 1; i >= 0 && ok; --i) {
			while (j && b[j] == b[j - 1]) {
				++amt[b[j]];
				--j;
			}
			if (j >= 0 && a[i] == b[j]) --j;
			else {
				if (!amt[a[i]]) ok = 0;
				else --amt[a[i]];
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}