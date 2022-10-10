#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 88;
// dp(thing, last pos + 1, changes remaining) = min bad
int n;
std::vector<int> a;
int memo[ms][ms][ms*ms / 2];
int dp(int on, int pos, int changes) {
	assert(pos <= n);
	if(changes < 0) return 1e9;
	int &ans = memo[on][pos][changes];
	if(ans != -1) return ans;
	if(on == (int) a.size()) {
		return ans = (n - pos) * (n - pos - 1) / 2;
	}
	ans = 1e9;
	for(int i = pos; i < n - ((int) a.size() - on - 1); i++) {
		ans = std::min(ans, dp(on+1, i+1, changes - abs(i - a[on])) + (i - pos) * (i - pos - 1) / 2);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	memset(memo, -1, sizeof memo);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(x == 1) {
			a.push_back(i);
		}
	}
	int m = n - (int) a.size();
	int pairs = m * (m-1) / 2;
	for(int i = 0; i <= n * (n - 1) / 2; i++) {
		std::cout << pairs - dp(0, 0, std::min(i, (int) a.size() * (n - (int) a.size()))) << (i == n * (n - 1) / 2 ? '\n' : ' ');
	}
}