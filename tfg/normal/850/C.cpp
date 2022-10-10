#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector< std::pair<int, int> > factors(int x) {
	std::vector< std::pair<int, int> > ans;
	for(int i = 2; i * i <= x; i++) {
		int e = 0;
		while(x % i == 0) {
			x /= i;
			e++;
		}
		if(e > 0) {
			ans.emplace_back(i, e);
		}
	}
	if(x > 1) {
		ans.emplace_back(x, 1);
	}
	return ans;
}

std::map<int, int> memo;

int dp(int mask) {
	if(mask == 0) return mask;
	if(memo.count(mask)) return memo[mask];
	int ha = 0;
	for(int i = 0; (1 << i) <= mask; i++) {
		ha |= 1 << dp((mask >> (i+1)) | (mask & ((1 << i) - 1)));
	}
	int ans = 0;
	while(ha & (1 << ans)) ans++;
	return memo[mask] = ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::map<int, int> wtf;
	while(n--) {
		int x;
		std::cin >> x;
		auto got = factors(x);
		for(auto p : got) {
			wtf[p.first] |= 1 << (p.second - 1);
		}
	}
	int nim = 0;
	for(auto p : wtf) {
		nim ^= dp(p.second);
	}
	std::cout << (nim == 0 ? "Arpa\n" : "Mojtaba\n");
}