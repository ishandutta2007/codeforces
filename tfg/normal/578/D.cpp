#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int n, m;
std::string str;

long long memo[ms][8][26];

long long dp(int on, int mask, int last) {
	long long &ans = memo[on][mask-1][last];
	if(ans != -1) return ans;
	ans = 0;
	if(on == n) {
		return ans = 1;
	}
	if(mask == 8) {
		for(int i = 0; i < m; i++) {
			ans += dp(on+1, str[on] - 'a' == i ? 8 : 7, i);
		}
		//std::cout << "on " << on << ", " << mask << ", " << last << " got " << ans << '\n';
		return ans;
	}
	for(int i = 0; i < m; i++) {
		int toMask = 0;
		if(mask & 4) {
			// skipping both
			if(i == str[on] - 'a') {
				toMask |= 4;
			}
		}
		if(mask & 2) {
			// skipping mine
			if(str[on-1] - 'a' == i) {
				toMask |= 6;
			}
		}
		if(mask & 1) {
			// skipping given
			if(str[on] - 'a' == last) {
				toMask |= 5;
			}
		}
		//std::cout << "from " << on << ", " << mask << ", " << last << " using " << char(i + 'a') << " got mask " << toMask << '\n';
		if(toMask) {
			ans += dp(on + 1, toMask, i);
		}
	}
	//std::cout << "on " << on << ", " << mask << ", " << last << " got " << ans << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	memset(memo, -1, sizeof memo);
	std::cin >> n >> m >> str;
	std::cout << dp(0, 8, 0) - 1 << '\n';
}