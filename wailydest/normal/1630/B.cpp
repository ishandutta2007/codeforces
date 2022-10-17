#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

const int N = 200000;
int t, n, k, a[N], amt[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		memset(amt, 0, n << 2);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
			++amt[a[i]];
		}
		int in = -n;
		std::pair<int, std::pair<int, int> > ans;
		ans.first = ~(1 << 31);
		for (int i = 0, j = 0; i < n; ++i) {
			while (in < k && j < n) {
				in += 2 * amt[j];
				++j;
			}
			if (in >= k) ans = std::min(ans, std::make_pair(j - i, std::make_pair(i, j)));
			in -= 2 * amt[i];
		}
		printf("%d %d\n", ans.second.first + 1, ans.second.second);
		for (int i = 0; k; --k) {
			int fi = i, s = 0;
			while (s <= 0 || i < n && k == 1) {
				s += a[i] >= ans.second.first && a[i] < ans.second.second ? 1 : -1;
				++i;
			}
			printf("%d %d\n", fi + 1, i);
		}
	}
	return 0;
}