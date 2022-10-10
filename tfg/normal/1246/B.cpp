#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int prime[ms];
int f[ms];

std::vector<std::pair<int, int>> getFactors(int x, int k) {
	std::vector<std::pair<int, int>> ans;
	while(x > 1) {
		int p = prime[x];
		int e = 0;
		while(x % p == 0) {
			x /= p;
			e++;
		}
		e %= k;
		if(e != 0) {
			ans.emplace_back(p, e);
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		if(prime[i]) continue;
		for(int j = i; j < ms; j += i) {
			prime[j] = i;
		}
	}
	int n, k;
	std::cin >> n >> k;
	long long ans = 0;
	while(n--) {
		int x;
		std::cin >> x;
		auto factors = getFactors(x, k);
		int mine = 1;
		long long other = 1;
		for(auto p : factors) {
			for(int i = 0; i < p.second; i++) {
				mine *= p.first;
			}
			for(int i = 0; i < k - p.second; i++) {
				other = std::min(other * p.first, (long long) ms + 1LL);
			}
		}
		if(other < ms) {
			ans += f[other];
		}
		f[mine]++;
	}
	std::cout << ans << '\n';
}