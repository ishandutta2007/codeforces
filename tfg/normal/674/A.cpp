#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
	}
	std::vector<int> ans(n, 0);
	for(int l = 0; l < n; l++) {
		std::vector<int> f(n, 0);
		int cur[2] = {-1, -1};
		for(int r = l; r < n; r++) {
			f[a[r]]++;
			if(f[a[r]] > cur[0]) {
				cur[0] = f[a[r]];
				cur[1] = a[r];
			} else if(f[a[r]] == cur[0] && a[r] < cur[1]) {
				cur[1] = a[r];
			}
			ans[cur[1]]++;
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}