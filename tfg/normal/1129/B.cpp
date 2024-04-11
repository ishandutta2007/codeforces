#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long dumb(std::vector<int> a) {
	int n = (int) a.size();
	long long ans = 0, cur = 0;
	int k = -1;
	for(int i = 0; i < n; i++) {
		cur += a[i];
		if(cur < 0) {
			cur = 0;
			k = i;
		}
		ans = std::max(ans, (i-k) * cur);
	}
	return ans;
}

long long brute(std::vector<int> a) {
	int n = (int) a.size();
	long long ans = 0;
	for(int l = 0; l < n; l++) {
		long long cur = 0;
		for(int r = l; r < n; r++) {
			cur += a[r];
			ans = std::max(ans, (r-l+1) * cur);
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long k;
	std::cin >> k;
	//k = rng() % 1000000000 + 1;
	std::vector<int> ans;
	for(int i = 3; 1; i++) {
		// 2 * x - i == k
		// x == (k + i) / 2
		//std::cout << "testing " << i << std::endl;
		if((k + i) % 2 == 0 && (k + i) / 2 <= 1000000LL * (i - 2)) {
			long long x = (k + i) / 2;
			ans.push_back(0);
			ans.push_back(-1);
			for(int j = 2; j < i; j++) {
				long long use = std::min(x, 1000000LL);
				x -= use;
				ans.push_back((int) use);
			}
			break;
		}
	}
	//std::cout << "(" << brute(ans) << ", " << dumb(ans) << ")\n";
	std::cout << ans.size() << '\n';
	assert(brute(ans) - dumb(ans) == k && ans.size() <= 2000);
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}