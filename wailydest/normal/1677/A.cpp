#include <cstdio>

const int N = 5000;
int t, n, p[N], amt[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			--p[i];
		}
		long long ans = 0;
		for (int j = 0; j < n; ++j) amt[j] = 0;
		for (int i = n - 1; i >= 0; --i) {
			int cnt = 0;
			for (int j = i - 1; j >= 0; --j) {
				if (p[j] < p[i]) ans += cnt;
				cnt += amt[p[j]];
			}
			for (int j = p[i]; j < n; ++j) ++amt[j];
		}
		printf("%lld\n", ans);
	}
	return 0;
}