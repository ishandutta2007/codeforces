#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Person {
	int mask;
	long long cost, monitors;

	void read() {
		int s = 0;
		mask = 0;
		std::cin >> cost >> monitors >> s;
		while(s--) {
			int x;
			std::cin >> x;
			mask |= 1 << (x-1);
		}
	}

	bool operator < (const Person &o) const { return monitors < o.monitors; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	long long b;
	std::cin >> n >> m >> b;
	std::vector<Person> a(n);
	for(auto &p : a) {
		p.read();
	}
	std::sort(a.begin(), a.end());
	const long long INF = 2e18;
	long long ans = INF;
	std::vector<long long> dp(1 << m, INF);
	dp[0] = 0;
	for(auto p : a) {
		for(int i = 0; i < (1 << m); i++) {
			dp[i|p.mask] = std::min(dp[i|p.mask], dp[i] + p.cost);
		}
		ans = std::min(ans, dp.back() + b * p.monitors);
	}
	if(ans >= INF) ans = -1;
	std::cout << ans << '\n';
}