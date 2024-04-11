#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> freq(30, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		int x;
		std::cin >> x;
		freq[x]++;
	}
	int ans = 0;
	std::sort(a.begin(), a.end());
	for(int i = 0; i < 30; i++) {
		/*for(int j = 0; j < n; j++) {
			std::cout << a[j] << (j+1==n?'\n':' ');
		}*/
		for(auto &v : a) {
			if(v % 2 && freq[i]) {
				v--;
				freq[i]--;
				ans++;
			}
		}
		for(auto &v : a) {
			while(v && freq[i]) {
				v--;
				freq[i]--;
				ans++;
			}
		}
		/*for(int j = 0; j < n; j++) {
			std::cout << a[j] << (j+1==n?'\n':' ');
		}*/
		for(auto &v : a) {
			v /= 2;
		}
	}
	std::cout << ans << '\n';
}