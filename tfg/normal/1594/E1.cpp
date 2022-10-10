#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 60 * 2020;
const int MOD = 1e9 + 7;

int c = 1;
int memo[66][8];
int to[ms][2], force[ms];

void add(long long val, int col) {
	int on = 0;
	std::string str;
	while(val != 1) {
		str += char('0' + val % 2);
		val /= 2;
	}
	std::reverse(str.begin(), str.end());
	for(auto ch : str) {
		int v = ch - '0';
		if(to[on][v] == -1) {
			to[on][v] = c++;
		}
		on = to[on][v];
	}
	assert(force[on] == -1);
	force[on] = col;
}

int dp(int on, int last, int rest) {
	if(on == -1 && memo[rest][last] != -1) {
		return memo[rest][last];
	}
	int ans = 0;
	int forced = (on == -1 ? -1 : force[on]);
	if(rest) {
		for(int i = 0; i < 6; i++) if(last / 2 != i / 2) if(forced == -1 || i == forced) {
			int wtf[2] = {0, 0};
			wtf[0] = (wtf[0] + dp(on == -1 ? -1 : to[on][0], i, rest-1)) % MOD;
			wtf[1] = (wtf[1] + dp(on == -1 ? -1 : to[on][1], i, rest-1)) % MOD;
			ans = (int) ((ans + (long long) wtf[0] * wtf[1]) % MOD);
		}
	} else {
		for(int i = 0; i < 6; i++) if(last / 2 != i / 2) if(forced == -1 || i == forced) {
			ans++;
		}
	}
	if(on == -1) {
		memo[rest][last] = ans;
		//std::cout << "at (" << rest << ", " << last << ") got " << ans << '\n';
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int k;
	std::cin >> k;
	int n = 0;
	//std::cin >> n;
	memset(force, -1, sizeof force);
	memset(memo, -1, sizeof memo);
	memset(to, -1, sizeof to);
	std::map<std::string, int> mp;
	mp["white"] = 0;
	mp["yellow"] = 1;
	mp["green"] = 2;
	mp["blue"] = 3;
	mp["red"] = 4;
	mp["orange"] = 5;
	while(n--) {
		long long id;
		std::string col;
		std::cin >> id >> col;
		add(id, mp[col]);
	}
	std::cout << dp(0, 6, k-1) << '\n';
}