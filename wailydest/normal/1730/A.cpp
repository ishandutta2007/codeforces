#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n, c, cnt[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &c);
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			++cnt[x - 1];
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			ans += std::min(c, cnt[i]);
			cnt[i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}