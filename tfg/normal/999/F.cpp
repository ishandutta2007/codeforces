#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	const int ms = 100500;
	std::vector<int> cards(ms, 0);
	std::vector<int> people(ms, 0);
	std::vector<int> cost(k + 1, 0);
	for(int i = 0; i < n * k; i++) {
		int t;
		std::cin >> t;
		cards[t]++;
	}
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		people[t]++;
	}
	for(int i = 1; i <= k; i++) {
		std::cin >> cost[i];
	}
	auto getCost = [&](int p, int c) -> int {
		std::vector<int> dp(c + 1, 0);
		while(p--) {
			for(int i = c; i > 0; i--) {
				for(int j = 1; j <= i && j <= k; j++) {
					dp[i] = std::max(dp[i], dp[i - j] + cost[j]);
				}
			}
		}
		//std::cout << "solved for " << c << ", " << p << ", got " << dp.back() << std::endl;
		return dp.back();
	};
	int ans = 0;
	for(int i = 0; i < ms; i++) {
		if(people[i]) {
			ans += getCost(people[i], cards[i]);
		}
	}
	std::cout << ans << std::endl;
}