#include <cstdio>
#include <cassert>
#include <algorithm>

const int N = 2000;
const int LG = 30;
int t, n, top[LG], u[LG], a[N];

int find(int a) {
	if (top[a] == -1) return a;
	return top[a] = find(top[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) top[b] = a;
}

void run() {
	for (int i = 0; i < LG; ++i) {
		top[i] = -1;
		u[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			int fi = __builtin_ctz(a[i]);
			for (int j = 0; j < LG; ++j) if (a[i] >> j & 1) {
				u[j] = i + 1;
				merge(j, fi);
			}
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int z = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			z += !a[i];
		}
		int opt = ~(1 << 31), id, d;
		for (int i = 0; i < n; ++i) if (a[i]) {
			int t = 0;
			for (int j = 0; a[i] - j > 0 && j <= LG + 2; ++j) if ((a[i] - j & t) == t) {
				a[i] -= j;
				int ans = 0;
				run();
				int dif = z;
				for (int i = 0; i < LG; ++i) if (u[i] && top[i] == -1) ++dif;
				if (dif > 1) ans += dif - 1 + !u[0];
				ans += j;
				if (ans < opt) {
					opt = ans;
					id = i;
					d = j;
				}
				while ((t & a[i]) == t) t = t << 1 | 1;
				a[i] += j;
			}
		}
		if (opt == ~(1 << 31)) {
			opt = n;
			id = d = 0;
		}
		printf("%d\n", opt);
		a[id] -= d;
		run();
		int dif = z;
		for (int i = 0; i < LG; ++i) if (u[i] && top[i] == -1) ++dif;
		if (dif > 1) for (int i = 0; i < LG; ++i) if (u[i] && top[i] == -1 && find(0) != i) ++a[u[i] - 1];
		for (int i = 0; i < n; ++i) {
			a[i] = std::max(a[i], 1);
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}