#include <iostream>
#include <set>

const int ms = 100100;

int cost[ms];

int main() {
	std::set<int> nums;
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int t;
		std::cin >> t;
		auto it = nums.upper_bound(t);
		if(it == nums.end()) {
			cost[t]--;
		} else {
			int to = *it;
			it++;
			if(it == nums.end()) {
				cost[to]++;
			}
		}
		nums.insert(t);
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		if(cost[i] > cost[ans]) {
			ans = i;
		}
	}
	std::cout << ans << '\n';
}