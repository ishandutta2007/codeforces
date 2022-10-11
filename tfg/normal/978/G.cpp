#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<ii>> events(n);
	std::vector<int> need(n, 0);
	std::vector<int> test(n, -1);
	std::vector<int> ans(n, -1);
	for(int i = 0; i < m; i++) {
		int l, r, c;
		std::cin >> l >> r >> c;
		l--;r--;
		events[l].push_back(ii(r, c));
		test[r] = ans[r] = i;
	}
	for(int i = 0; i < n; i++) {
		for(int k = 0; k < events[i].size(); k++) {
			need[events[i][k].first] += events[i][k].second;
		}
		if(test[i] != -1) {
			if(need[i] > 0) {
				std::cout << "-1\n";
				return 0;
			}
			ans[i] = m;
		} else {
			for(int j = i + 1; j < n; j++) {
				if(need[j] > 0) {
					need[j]--;
					ans[i] = test[j];
					break;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}