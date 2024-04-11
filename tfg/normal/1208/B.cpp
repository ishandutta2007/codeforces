#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(auto &v : a) std::cin >> v;
	std::set<int> st;
	int ans = 128973;
	for(int l = 0, r = n; l <= n; l++) {
		if(l > 0) {
			while(r < n && st.count(a[l-1])) {
				st.erase(a[r++]);
			}
			if(st.count(a[l-1])) break;
			st.insert(a[l-1]);
		}
		while(r > 0 && !st.count(a[r-1])) {
			st.insert(a[--r]);
		}
		//std::cout << "got (" << l << ", " << r << "]\n";
		ans = std::min(ans, (r - l));
	}
	std::cout << ans << std::endl;
}