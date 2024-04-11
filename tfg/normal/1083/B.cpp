#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long k;
	std::cin >> n >> k;
	int on = 0;
	long long got = 1;
	long long ans = 0;
	std::string s, t;
	std::cin >> s >> t;
	assert(s <= t);
	if(k == 1 || s == t) {
		std::cout << n << '\n';
		return 0;
	}
	while(on < n && s[on] == t[on]) {
		ans++;
		on++;
	}
	got++;
	while(on < n) {
		ans += got;
		long long nxt = (got - 2) * 2 + 2;
		if(on + 1 < n && s[on + 1] == 'a') {
			nxt++;
		}
		if(on + 1 < n && t[on + 1] == 'b') {
			nxt++;
		}
		got = std::min(k, nxt);
		on++;
	}
	std::cout << ans << '\n';
}