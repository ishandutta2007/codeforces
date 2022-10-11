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
	int ans = 0;
	std::vector<int> a;
	int special = -1;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(ans <= 1 || special != x || cnt > 0) {
			ans++;
			if(!a.empty() && a.back() == x) {
				special = x;
				cnt = 0;
			} else if(x != special) {
				cnt++;
				if(cnt == 2) {
					special = -1;
					cnt = 0;
				}
			} else {
				cnt--;
			}
			a.push_back(x);
		}
	}
	std::cout << ans << '\n';
}