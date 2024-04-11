#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int f[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		f[v]++;
	}
	auto construct = [&](int x) {
		std::vector<int> ans;
		for(int i = 0; i < ms; i++) {
			int y = f[i] / x;
			while(y--) {
				ans.push_back(i);
			}
		}
		while(ans.size() > k) {
			ans.pop_back();
		}
		if(ans.size() < k) {
			ans.clear();
		}
		return ans;
	};
	int l = 0, r = n;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(construct(mid).size() == 0) {
			r = mid - 1;
		} else {
			l = mid;
		}
	}
	auto ans = construct(l);
	for(int i = 0; i < k; i++) {
		std::cout << ans[i] << (i + 1 == k ? '\n' : ' ');
	}
}