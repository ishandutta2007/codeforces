#include <bits/stdc++.h>
using namespace std;
int n, m, c, x;
int f[1020];
int g[1020];
int main() {
	scanf("%d%d%d", &n, &m, &c);
	memset(f, 0x3f, sizeof f);
	while (scanf("%d", &x) != EOF) {
		if (2 * x > c) {
			int p = lower_bound(g, g + n, x) - g - 1;
			g[p] = x;
			printf("%d\n", p + 1);
		} else {
			int p = upper_bound(f, f + n, x) - f;
			f[p] = x;
			printf("%d\n", p + 1);
		}
		fflush(stdout);
	}
	return 0;
}