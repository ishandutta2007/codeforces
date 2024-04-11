#include <cstdio>
#include <algorithm>

const int N = 1000005;
int n, m, C;
long long mx[N], r[N];

int main() {
	scanf("%d%d", &n, &C);
	for (int i = 0; i < n; ++i) {
		int c, d, h;
		scanf("%d%d%d", &c, &d, &h);
		mx[c] = std::max(mx[c], (long long)d * h);
	}
	for (int i = 1; i <= C; ++i) for (int j = i; j <= C; j += i) r[j] = std::max(r[j], mx[i] * (j / i));
	for (int i = 1; i <= C; ++i) r[i] = std::max(r[i], r[i - 1]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int d;
		long long h;
		scanf("%d%lld", &d, &h);
		int ans = std::upper_bound(r, r + C + 1, d * h) - r;
		if (ans == C + 1) printf("-1 ");
		else printf("%d ", ans);
	}
	printf("\n");
	return 0;
}