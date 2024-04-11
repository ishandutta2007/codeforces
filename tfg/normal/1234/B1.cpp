#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::set<int> got;
	std::set<std::pair<int, int>> msg;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(got.count(x)) {
			// do nothing
		} else {
			if(msg.size() == k) {
				got.erase(msg.begin()->second);
				msg.erase(msg.begin());
			}
			got.insert(x);
			msg.insert(std::pair<int, int>(i, x));
		}
	}
	std::cout << msg.size() << '\n';
	std::vector<int> ans;
	for(auto it : msg) {
		ans.push_back(it.second);
	}
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[(int) ans.size()-i-1] << (i + 1 == n ? '\n' : ' ');
	}
}