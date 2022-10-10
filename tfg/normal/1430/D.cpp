#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::string str;
		std::cin >> n >> str;
		std::vector<int> a;
		for(int l = 0, r = 0; l < n; l = r) {
			while(l < n && str[l] == str[r]) r++;
			a.push_back(r - l);
		}
		int ans = 0;
		for(int l = 0, r = 0; l < (int) a.size(); l++) {
			r = std::max(r, l);
			while(r < (int) a.size() && a[r] == 1) r++;
			ans++;
			if(r == (int) a.size()) {
				l++;
			} else {
				a[r]--;
			}
		}
		std::cout << ans << '\n';
	}
}