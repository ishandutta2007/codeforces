#include <cstdio>

const int N = 200000;
int t, n, a[N], b[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool ok = 1;
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int mn = ~(1 << 31), pos = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", b + i);
			if (b[i] < a[i]) ok = 0;
			if (b[i] < mn) {
				mn = b[i];
				pos = i;
			}
		}
		int pr = mn;
		for (int i = (pos - 1 + n) % n; i != pos; i = (i - 1 + n) % n) {
			if (a[i] != b[i] && b[i] > pr + 1) ok = 0;
			pr = b[i];
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}