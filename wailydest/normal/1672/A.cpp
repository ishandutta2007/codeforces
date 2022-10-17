#include <cstdio>

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int r = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			r ^= (x & 1) ^ 1;
		}
		printf("%s\n", r ^ 1 ? "maomao90" : "errorgorn");
	}
	return 0;
}