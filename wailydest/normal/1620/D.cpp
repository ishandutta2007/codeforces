#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100;
int t, n, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			mx = std::max(mx, a[i]);
		}
		int ans = ~(1 << 31), add = std::max(mx / 3 - 1, 0), cur = add * 3;
		for (int i = 0; i <= 2; ++i) for (int j = 0; j <= 2; ++j) for (int k = 0; k <= 2; ++k) {
			std::vector<int> all;
			for (int l = 0; l < i; ++l) all.push_back(1);
			for (int l = 0; l < j; ++l) all.push_back(2);
			for (int l = 0; l < k; ++l) all.push_back(3);
			std::vector<bool> make(20, 0);
			make[0] = 1;
			for (int i = 0; i < (int)all.size(); ++i) for (int j = 19 - all[i]; j >= 0; --j) if (make[j]) make[j + all[i]] = 1;
			bool ok = 1;
			for (int i = 0; i < n && ok; ++i) {
				ok = 0;
				int k = a[i] / 3;
				if (k <= add && make[a[i] - k * 3]) ok = 1;
				--k;
				if (k >= 0 && make[a[i] - k * 3]) ok = 1;
			}
			if (ok) ans = std::min(ans, add + i + j + k);
		}
		printf("%d\n", ans);
	}
	return 0;
}