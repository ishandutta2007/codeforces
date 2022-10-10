#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	const int ms = 1001000;
	std::vector<int> nxt(ms, 0);
	while(n--) {
		int x;
		std::cin >> x;
		nxt[x] = x;
	}
	for(int i = 1; i < ms; i++) {
		nxt[i] = std::max(nxt[i], nxt[i-1]);
	}
	int ans = 0;
	for(int i = 2; i < ms; i++) {
		if(nxt[i] != i) continue;
		for(int j = i; j < ms; j += i) {
			if(nxt[j-1] > i) {
				ans = std::max(ans, nxt[j-1] % i);
			}
		}
		ans = std::max(ans, nxt.back() % i);
	}
	std::cout << ans << '\n';
}