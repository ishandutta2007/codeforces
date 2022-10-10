#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long s;
	int n;
	std::cin >> n >> s;
	if(s > (long long) n * (n + 1) / 2 || s < n * 2 - 1) {
		std::cout << "No\n";
		return 0;
	}
	std::cout << "Yes\n";
	/*if(s == (long long) n * (n + 1) / 2) {
		for(int i = 1; i < n; i++) {
			std::cout << i << (i + 1 == n ? '\n' : ' ');
		}
		return 0;
	}
	if(s == n * 2 - 1) {
		for(int i = 1; i < n; i++) {
			std::cout << 1 << (i + 1 == n ? '\n' : ' ');
		}
		return 0;
	}*/
	int l = 1, r = n - 1;
	auto solve = [&](int x) {
		//std::cout << "Testing for " << x << std::endl;
		std::vector<int> ans;
		std::vector<int> freq(n, 1);
		std::vector<long long> wtf(n, x - 1);
		wtf.back()++;
		long long diff = (long long) n * (n + 1) / 2 - s;
		int pr = n-1;
		int pl = 0;
		while(diff > 0) {
			//std::cout << "diff is " << diff << std::endl;
			//std::cout << "entering (" << pl << ", " << pr << ")" << std::endl;
			if(pl + 1 >= pr) return ans;
			if(!freq[pr]) {
				//std::cout << "third" << std::endl;
				pr--;
				pl = std::max(0, pl - 1);
			} else if(!wtf[pl]) {
				//std::cout << "first" << std::endl;
				pl++;
			} else if(pr - pl - 1 > diff) {
				//std::cout << "second" << std::endl;
				pl++;
			} else {
				//std::cout << "fourth" << std::endl;
				diff -= pr - pl - 1;
				wtf[pr] -= x;
				freq[pr]--;
				freq[pl+1]++;
				wtf[pl+1] += x;
				wtf[pr-1]++;
				wtf[pl]--;
			}
		}
		for(int i = 0; i < n; i++) {
			//std::cout << freq[i] << (i + 1 == n ? '\n' : ' ');
		}
		//std::cout << "diff is " << diff << std::endl;
		assert(diff == 0);
		// get answer
		std::vector<int> h(1, 0);
		ans.push_back(-1);
		for(int i = 0; i < n; i++) {
			if(h[i] + 1 == n) continue;
			int use = std::min(x, freq[h[i]+1]);
			//std::cout << "for " << i << " of height " << h[i] << " using " << use << std::endl;
			while(use--) {
				freq[h[i]+1]--;
				ans.push_back(i + 1);
				h.push_back(h[i] + 1);
			}
		}
		assert((int) ans.size() == n);
		//std::cout << "got answer of size " << (int) ans.size() << std::endl;
		return ans;
	};
	assert(l <= r);
	while(l != r) {
		int mid = (l + r) / 2;
		if(solve(mid).size() > 0) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	auto ans = solve(l);
	assert((int) ans.size() == n);
	for(int i = 1; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}