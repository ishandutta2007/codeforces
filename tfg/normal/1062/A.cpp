#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> a;
	int n;
	std::cin >> n;
	a.push_back(0);
	while(n--) {
		int v;
		std::cin >> v;
		a.push_back(v);
	}
	a.push_back(1001);
	n = (int) a.size();
	int ans = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[r] - a[l] == r - l) {
			r++;
		}
		//std::cout << "group [" << l << ", " << r << ")\n";
		ans = std::max(ans, r - l - 2);
	}
	std::cout << ans << '\n';
}