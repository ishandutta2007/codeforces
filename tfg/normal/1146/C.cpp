#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int qry(std::vector<int> v1, std::vector<int> v2) {
	if(v1.size() == 0 || v2.size() == 0) return 0;
	std::cout << v1.size() << ' ' << v2.size();
	for(auto v : v1) std::cout << ' ' << v;
	for(auto v : v2) std::cout << ' ' << v;
	std::cout << std::endl;
	int ans;
	std::cin >> ans;
	return ans;
}

void solve() {
	int n;
	std::cin >> n;
	int ans = 0;
	for(int e = 0; e < 9; e++) {
		std::vector<int> v1, v2;
		for(int i = 0; i < n; i++) {
			if(i & (1 << e)) {
				v1.push_back(i + 1);
			} else {
				v2.push_back(i + 1);
			}
		}
		ans = std::max(ans, qry(v1, v2));
	}
	std::cout << "-1 " << ans << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}