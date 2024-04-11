#include <cstdio>
#include <algorithm>

const int N = 100005;
int tt, n, x[N], t[N], mx[N];
std::pair<int, int> ord[N];

int main() {
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &ord[i].first);
		int b = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &ord[i].second);
			b = std::max(b, ord[i].second);
		}
		std::sort(ord, ord + n);
		for (int i = 0; i < n; ++i) {
			x[i] = ord[i].first;
			x[i] *= 2;
			t[i] = b - ord[i].second;
		}
		if (n == 1) printf("%d\n", x[0] / 2);
		else {
			mx[n] = 1 << 31;
			for (int i = n - 1; i >= 0; --i) mx[i] = std::max(mx[i + 1], x[i] - t[i] * 2);
			int mn1 = ~(1 << 31);
			std::pair<int, int> ans;
			ans.first = ~(1 << 31);
			for (int i = 0; i < n; ++i) {
				if (i) {
					int meet = mx[i] + mn1 >> 1;
					meet = std::max(meet, x[i - 1]);
					meet = std::min(meet, x[i]);
					ans = std::min(ans, std::make_pair(std::max(0, std::max(mx[i] - meet, meet - mn1)), meet));
					for (int t = 0; t < 2; ++t) {
						if (!t) meet = x[i - 1];
						else meet = x[i];
						ans = std::min(ans, std::make_pair(std::max(0, std::max(mx[i] - meet, meet - mn1)), meet));
					}
				}
				mn1 = std::min(mn1, x[i] + t[i] * 2);
			}
			printf("%d", ans.second >> 1);
			if (ans.second & 1) printf(".5");
			printf("\n");
		}
	}
	return 0;
}