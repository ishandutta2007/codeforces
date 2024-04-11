#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool isPrime(int x) {
	if(x == 1) return false;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}

std::vector<int> goodValues, badValues;
unsigned char memo[1 << 27];
int trans[27];

unsigned char dp(int on) {
	if(on == 0) return 1;
	unsigned char &ans = memo[on];
	if(ans != 0) return ans;
	int wtf = 1;
	for(int i = 0; i < 27; i++) {
		if(on & (1 << i)) {
			wtf |= 1 << dp(on & trans[i]);
		}
	}
	while(wtf & (1 << ans)) ans++;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 2; i <= 28; i++) {
		goodValues.push_back(i);
	}
	// 4 bad values
	// 17 19 23 29
	std::cerr << goodValues.size() << '\n';
	for(int i = 0; i < (int) goodValues.size(); i++) {
		for(int j = 0; j < (int) goodValues.size(); j++) {
			if(goodValues[j] % goodValues[i]) {
				trans[i] |= 1 << j;
			}
		}
	}
	std::vector<int> vals;
	vals.push_back(0);
	vals.push_back(1);
	for(int i = 2; i <= 29; i++) {
		int mask = 0;
		for(int j = 0; j < (int) goodValues.size(); j++) {
			if(goodValues[j] <= i) {
				mask |= 1 << j;
			}
		}
		vals.push_back(dp(mask));
		//std::cerr << "at " << i << " got nimber " << vals[i] << " from mask " << mask << '\n';
	}
	vals[29] = 12;
	int ans = 0;
	std::vector<bool> f(1e5, false);
	int all = n;
	for(int i = 2; i * i <= n; i++) {
		if(f[(int) i]) continue;
		int cur = 0;
		for(long long x = i; x <= n; x *= i) {
			cur++;
			if((int) x < (int) f.size()) {
				f[(int) x] = true;
			}
		}
		ans ^= vals[cur];
		assert(cur < (int) vals.size());
		//std::cout << "at " << i << " got " << cur << '\n';
		all -= cur;
	}
	assert(all > 0);
	ans ^= all % 2 ? vals[1] : vals[0];
	std::cout << (ans ? "Vasya\n" : "Petya\n");
}