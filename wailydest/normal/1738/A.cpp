#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100000;
int t, n, type[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		std::vector<int> a[2];
		for (int i = 0; i < n; ++i) scanf("%d", type + i);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			ans += x;
			a[type[i]].push_back(x);
		}
		std::sort(a[0].begin(), a[0].end());
		std::sort(a[1].begin(), a[1].end());
		int cnt = std::min(a[0].size(), a[1].size());
		for (int j = 0; j < 2; ++j) for (int i = a[j].size() - cnt; i < a[j].size(); ++i) ans += a[j][i];
		if (a[0].size() == a[1].size()) ans -= std::min(a[0].front(), a[1].front());
		printf("%lld\n", ans);
	}
	return 0;
}