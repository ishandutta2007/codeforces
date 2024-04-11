#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::vector<long long> sum(n+1, 0);
	for(int i = 0; i < n; i++) {
		sum[i+1] = sum[i] + a[i];
	}
	long long one = 0;
	for(int i = 0; i + 1 < n; i++) {
		one += sum[i+1];
	}
	int q;
	std::cin >> q;
	while(q--) {
		int k;
		std::cin >> k;
		long long ans = one;
		if(k != 1) {
			ans = 0;
			long long r = n;
			long long l = n-1;
			long long lvl = 0;
			while(r > 0) {
				//std::cout << "[" << l << ", " << r << ")" << std::endl;
				l = std::max(l, 0LL);
				ans += lvl * (sum[r] - sum[l]);
				long long hmm = k * (r - l);
				r = l;
				l = l - hmm;
				lvl++;
			}
		}
		std::cout << ans << (q == 0 ? '\n' : ' ');
	}
}