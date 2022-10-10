#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> to(n);
	for(int i = 0; i < n; i++) {
		std::cin >> to[i];
		to[i]--;
	}
	std::vector<bool> vis(n, false);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		std::vector<int> st(1, i);
		while(!vis[st.back()]) {
			vis[st.back()] = true;
			st.push_back(to[st.back()]);
		}
		int want = st.back();
		int val = a[want];
		st.pop_back();
		while(!st.empty() && st.back() != want) {
			val = std::min(val, a[st.back()]);
			st.pop_back();
		}
		if(st.empty()) val = 0;
		ans += val;
	}
	std::cout << ans << '\n';
}