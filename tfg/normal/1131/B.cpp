#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int last[2] = {0, 0};
	int ans = 1;
	while(n--) {
		int nxt[2];
		std::cin >> nxt[0] >> nxt[1];
		if(nxt[0] == last[0] && nxt[1] == last[1]) continue;
		if(std::min(nxt[0], nxt[1]) < std::max(last[0], last[1])) {
			
		} else {
			ans -= std::max(last[0], last[1]) - std::min(nxt[0], nxt[1]);
			if(last[0] != last[1]) ans++;
		}
		last[0] = nxt[0];
		last[1] = nxt[1];
	}
	std::cout << ans << '\n';
}