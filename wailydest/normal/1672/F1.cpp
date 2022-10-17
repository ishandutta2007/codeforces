#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

const int N = 200000;
int t, n, amt[N], a[N];
std::vector<std::pair<int, int> > vec[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(amt, 0, n << 2);
		for (int i = 0; i < n; ++i) vec[i].clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
			vec[amt[a[i]]++].push_back(std::make_pair(a[i], i));
		}
		for (int i = 0; i < n; ++i) {
			std::sort(vec[i].begin(), vec[i].end());
			for (int k = 0; k < (int)vec[i].size(); ++k) a[vec[i][(k + 1) % vec[i].size()].second] = vec[i][k].first;
		}
		for (int i = 0; i < n; ++i) printf("%d ", a[i] + 1);
		printf("\n");
	}
	return 0;
}