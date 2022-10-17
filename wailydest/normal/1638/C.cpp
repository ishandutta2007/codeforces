#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 100000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		std::vector<int> vec;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			int mx = x;
			while (!vec.empty() && x < vec.back()) {
				mx = std::max(mx, vec.back());
				vec.pop_back();
				--ans;
			}
			vec.push_back(mx);
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}