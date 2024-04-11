#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(n+1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i-1];
	}
	std::set<long long> st;
	long long ans = 0;
	for(int l = 0, r = 0; l < n; l++) {
		while(r <= n && !st.count(a[r])) st.insert(a[r++]);
		ans += (r - l) - 1;
		st.erase(a[l]);
	}
	std::cout << ans << '\n';
}