#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> ans;
	for(int k = 1; k < n; k += k) {
		std::vector<int> cur;
		for(int i = 0; i < n; i++) {
			if(i & k) {
				cur.push_back(i + 1);
			}
		}
		ans.push_back(cur);
	}
	std::cout << ans.size() << '\n';
	for(auto v : ans) {
		std::cout << v.size() << ' ';
		for(int i = 0; i < (int) v.size(); i++) {
			std::cout << v[i] << (i + 1 == (int) v.size() ? '\n' : ' ');
		}
	}
}