#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<bool> got(1e7, false);
	while(n--) {
		int t;
		std::cin >> t;
		t = std::min(t, int(1e7) - 1);
		got[t] = true;
	}
	std::vector<int> ans;
	for(int i = 1; i <= m; i++) {
		if(!got[i]) {
			ans.push_back(i);
			m -= i;
		}
	}
	std::cout << ans.size() << std::endl;
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}