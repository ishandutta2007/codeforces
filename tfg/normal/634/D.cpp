#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int d, n, m;
	std::cin >> d >> n >> m;
	std::vector<std::pair<int, int>> gas;
	while(m--) {
		int x, p;
		std::cin >> x >> p;
		gas.emplace_back(x, p);
	}
	std::sort(gas.begin(), gas.end());
	std::map<int, int> fuel;
	int sum = n;
	fuel[0] += n;
	int on = 0;
	long long ans = 0;
	auto go = [&](int to) {
		int dist = to - on;
		if(dist > sum) return false;
		sum -= dist;
		while(dist > 0) {
			//std::cout << fuel.size() << std::endl;
			auto it = fuel.begin();
			if(it->second > dist) {
				it->second -= dist;
				ans += (long long) dist * it->first;
				dist = 0;
			} else {
				dist -= it->second;
				ans += (long long) it->first * it->second;
				fuel.erase(it);
			}
		}
		on = to;
		return true;
	};
	auto refuel = [&](int cost) {
		fuel[cost] += n;
		sum += n;
		while(sum > n) {
			auto it = fuel.end();
			it--;
			if(it->second > sum - n) {
				//std::cout << "erasing " << sum - n << " from " << it->first << ", " << it->second << std::endl;
				it->second -= sum - n;
				sum -= sum - n;
			} else {
				//std::cout << "erasing " << it->second << " from " << it->first << ", " << it->second << std::endl;
				sum -= it->second;
				fuel.erase(it);
			}
		}
		//std::cout << "sum is " << sum << '\n';
	};
	gas.emplace_back(d, 0);
	for(auto g : gas) {
		//std::cout << "at " << g.first << ", " << g.second << "\n";
		if(!go(g.first)) {
			std::cout << "-1\n";
			return 0;
		}
		refuel(g.second);
	}
	std::cout << ans << '\n';
}