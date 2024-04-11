#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ii;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> ans(n, 0);
	std::vector<ii> skill(n);
	for(int i = 0; i < n; i++) {
		std::cin >> skill[i].first;
		skill[i].second = i;
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		if(skill[u].first > skill[v].first) {
			ans[u]--;
		} else if(skill[v].first > skill[u].first) {
			ans[v]--;
		}
	}
	std::sort(skill.begin(), skill.end());
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && skill[l].first == skill[r].first) {
			ans[skill[r++].second] += l;
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}