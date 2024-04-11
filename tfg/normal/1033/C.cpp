#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> rev(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
		rev[a[i]] = i;
	}
	std::string ans(n, 'B');
	for(int i = n - 1; i >= 0; i--) {
		//std::cout << "on " << i << std::endl;
		//std::cout << "position is " << rev[i] << std::endl;
		for(int j = rev[i] + i + 1; j < n; j += i + 1) {
			if(a[j] > i && ans[j] == 'B') {
				//std::cout << "from position " << rev[i] << " to position " << j << std::endl;
				ans[rev[i]] = 'A';
			}
		}
		for(int j = rev[i] - i - 1; j >= 0; j -= i + 1) {
			if(a[j] > i && ans[j] == 'B') {
				//std::cout << "from position " << rev[i] << " to position " << j << std::endl;
				ans[rev[i]] = 'A';
			}
		}
	}
	std::cout << ans << std::endl;
}