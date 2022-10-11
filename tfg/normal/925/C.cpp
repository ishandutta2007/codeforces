#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 61;
	int n;
	std::cin >> n;
	std::vector<long long> a[ms];
	for(int i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		int j = 0;
		while((1LL << (j+1)) <= x) j++;
		a[j].push_back(x);
		//std::cout << "pushing " << x << " to " << j << '\n';
	}
	std::vector<long long> ans;
	long long cur = 0;
	for(int i = 0; i < n; i++) {
		bool got = false;
		for(int j = 0; j < ms && !got; j++) {
			if(a[j].empty() || (cur >> j) % 2 == 1) continue;
			//std::cout << "got " << j << std::endl;
			got = true;
			cur ^= a[j].back();
			ans.push_back(a[j].back());
			a[j].pop_back();
		}
		if(!got) {
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}