#include <cstdio>

const int N = 1000;
int t, n, p[N], ans[N];
bool u[N];

bool run(int i) {
	if (i == n) return 1;
	for (ans[i] = 0; ans[i] < n; ++ans[i]) {
		if (!u[ans[i]] && p[i] != ans[i]) {
			u[ans[i]] = 1;
			if (run(i + 1)) return 1;
			u[ans[i]] = 0;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			--p[i];
			u[i] = 0;
		}
		if (n == 1) printf("-1\n");
		else {
			run(0);
			for (int i = 0; i < n; ++i) printf("%d ", ans[i] + 1);
			printf("\n");
		}
	}
	return 0;
}