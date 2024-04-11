#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<bool> in(n, true);
	std::vector<int> st(n);
	for(int i = n-1; i >= 0; i--) {
		std::cin >> st[i];
		st[i]--;
	}
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		x--;
		if(!in[x]) {
			std::cout << 0 << (i + 1 == n ? '\n' : ' ');
			continue;
		}
		int ans = 1;
		while(st.back() != x) {
			ans++;
			in[st.back()] = false;
			st.pop_back();
		}
		in[x] = false;
		st.pop_back();
		std::cout << ans << (i + 1 == n ? '\n' : ' ');
	}
}