#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 505;
const int INF = 1e9;

std::string str;
int memo[ms][ms];

int dp(int l, int r) {
	if(l >= r) return 0;
	int &ans = memo[l][r];
	if(ans != -1) return ans;
	ans = r - l;
	for(int i = l; i < r; i++) {
			ans = std::min(ans, dp(l, i) + dp(i + 1, r) + (str[l-1] == str[i] ? 0 : 1));
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> str;
	str = "#" + str;
	memset(memo, -1, sizeof memo);
	std::cout << dp(1, n + 1) << '\n';
}