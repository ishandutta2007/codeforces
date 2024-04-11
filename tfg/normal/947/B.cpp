#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> vol(n);
	for(int i = 0; i < n; i++) {
		std::cin >> vol[i];
	}
	long long t = 0;
	std::multiset<long long> ha;
	for(int i = 0; i < n; i++) {
		long long ans = 0;
		long long x;
		std::cin >> x;
		ha.insert(t + vol[i]);
		while(!ha.empty() && *ha.begin() <= x + t) {
			ans += *ha.begin() - t;
			ha.erase(ha.begin());
		}
		ans += (long long) ha.size() * x;
		t += x;
		std::cout << ans << (i + 1 == n ? '\n' : ' ');
	}
}