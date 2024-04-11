#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, a, b, k;
	std::cin >> n >> a >> b >> k;
	std::vector<int> costs;
	while(n--) {
		int x;
		std::cin >> x;
		x %= a + b;
		if(x == 0) {
			x = a + b;
		}
		x -= a;
		if(x <= 0) {
			costs.push_back(0);
		} else {
			costs.push_back((x + a - 1) / a);
		}
		//std::cout << costs.back() << std::endl;
	}
	std::sort(costs.rbegin(), costs.rend());
	int ans = 0;
	while(!costs.empty() && k >= costs.back()) {
		k -= costs.back();
		//std::cout << "got " << costs.back() << std::endl;
		costs.pop_back();
		ans++;
	}
	std::cout << ans << std::endl;
}