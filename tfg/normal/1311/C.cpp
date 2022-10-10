#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::string str;
		std::cin >> str;
		std::vector<int> sum(n, 0);
		sum[n-1]++;
		while(m--) {
			int x;
			std::cin >> x;
			sum[x-1]++;
		}
		std::vector<int> f(26, 0);
		for(int i = n-1; i > 0; i--) {
			sum[i-1] += sum[i];
		}
		for(int i = 0; i < n; i++) {
			f[str[i]-'a'] += sum[i];
		}
		for(int i = 0; i < 26; i++) {
			std::cout << f[i] << (i == 25 ? '\n' : ' ');
		}
	}
}