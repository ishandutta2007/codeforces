#include <cstdio>

int query(int w) {
	printf("? %d\n", w);
	fflush(stdout);
	int h;
	scanf("%d", &h);
	return h;
}

int t, n;

int main() {
	scanf("%d", &n);
	int l = 1, r = 2001 * 2000;
	while (l < r) {
		int m = l + r >> 1;
		if (query(m) == 1) r = m;
		else l = m + 1;
	}
	int ans = r;
	for (int i = 2; i <= n; ++i) {
		while (true) {
			int next = (ans - 1) / i;
			if (next * i >= r - n + 1 && query(next) == i) ans = next * i;
			else break;
		}
	}
	printf("! %d\n", ans);
	return 0;
}