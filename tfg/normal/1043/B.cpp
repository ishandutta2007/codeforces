#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> ans;
	for(int s = 1; s <= n; s++) {
		std::vector<int> b(s);
		for(int j = 0; j < s; j++) {
			b[j] = a[j+1] - a[j];
		}
		bool valid = true;
		for(int i = 1; i <= n; i++) {
			valid = valid && a[i] - a[i-1] == b[(i-1) % s];
		}
		if(valid) {
			ans.push_back(s);
		}
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}