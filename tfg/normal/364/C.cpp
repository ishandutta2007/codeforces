#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool isPrime(int x) {
	if(x < 2) return false;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

const int ms = 1 << 10;

std::vector<int> masks[ms];
int pt[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int p = 0;
	int k = 2 * n * n;
	masks[0].push_back(1);
	int got = 0;
	auto pls = [&]() {
		std::vector<int> ans;
		std::vector<int> wtf;
		for(int i = 1; i < (1<<p); i++) {
			wtf.push_back(i);
			pt[i] = (int) masks[i].size();
		}
		std::vector<int> ha(p, 0);
		while((int) ans.size() < n) {
			while(1) {
				int ma = rng() % wtf.size();
				if(pt[wtf[ma]] == 0) {
					std::swap(wtf[ma], wtf.back());
					wtf.pop_back();
					continue;
				}
				ma = wtf[ma];
				ans.push_back(masks[ma][--pt[ma]]);
				for(int i = 0; i < p; i++) {
					if(ma & (1 << i)) {
						ha[i]++;
					}
				}
				break;
			}
		}
		for(int i = 0; i < p; i++) {
			if(ha[i] * 2 < n) {
				ans.clear();
			}
		}
		return ans;
	};
	for(int rep = 2; 1; rep++) {
		if(!isPrime(rep)) continue;
		for(int m = 0; m < (1 << p); m++) {
			for(auto x : masks[m]) {
				while(x * rep <= k) {
					x *= rep;
					masks[m | (1 << p)].push_back(x);
					got++;
				}
			}
		}
		p++;
		if(got < n) continue;
		for(int repp = 1; repp <= 10; repp++) {
			auto ans = pls();
			if(!ans.empty()) {
				for(int i = 0; i < n; i++) {
					std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
				}
				return 0;
			}
		}
	}

}