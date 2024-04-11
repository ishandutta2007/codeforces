#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 3030;

int cost[ms][3];
int memo[ms][2];
int n;
int dp(int on, int got) {
	int &ans = memo[on][got];
	if(ans != -1) return ans;
	ans = 0;
	if(on == n) {
		return ans = cost[on-1][got];
	} else {
		return ans = std::max(cost[on-1][got] + dp(on+1, 1), cost[on-1][got+1] + dp(on+1, 0));
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	memset(memo, -1, sizeof memo);
	std::cin >> n;
	for(int j = 0; j < 3; j++) {
		for(int i = 0; i < n; i++) {
			std::cin >> cost[i][j];
		}
	}
	std::cout << dp(1, 0) << std::endl;
}