#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b, h, w, n;
	std::cin >> a >> b >> h >> w >> n;
	std::vector<int> A(n);
	for(int i = 0; i < n; i++) {
		std::cin >> A[i];
	}
	std::sort(A.rbegin(), A.rend());
	std::vector<std::pair<int, int>> got;
	got.emplace_back((a-1)/h, (b-1)/w);
	got.emplace_back((b-1)/h, (a-1)/w);
	std::sort(got.begin(), got.end());
	
	int ans = 0;
	if(got[0].first + got[0].second == 0) {
		std::cout << ans << '\n';
		return 0;
	}
	for(auto x : A) {
		std::vector<std::pair<int, int>> haha;
		for(auto p : got) {
			haha.emplace_back(p.first, p.second / x);
			haha.emplace_back(p.first / x, p.second);
		}
		got = haha;
		std::sort(got.begin(), got.end());
		got.resize(std::unique(got.begin(), got.end()) - got.begin());
		//std::cout << got[0].first << ' ' << got[0].second << '\n';
		ans++;
		if(got[0].first + got[0].second == 0) {
			std::cout << ans << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}