#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, q;
	std::cin >> n >> m >> q;
	std::string txt, pat;
	std::cin >> txt >> pat;
	std::vector<int> sum(n + 1, 0);
	txt += std::string(pat.size(), '#');
	for(int i = 1; i <= n; i++) {
		if(pat == txt.substr(i - 1, pat.size())) {
			sum[i]++;
		}
		sum[i] += sum[i - 1];
	}
	for(int i = 0; i <= n; i++) {
		//std::cout << sum[i] << (i == n ? '\n' : ' ');
	}
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		r = r - (int) pat.size() + 1;
		if(r < l) {
			std::cout << "0\n";
		} else {
			std::cout << sum[r] - sum[l - 1] << '\n';
		}
	}
}