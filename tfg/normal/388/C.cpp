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
	std::vector<int> middle;
	int ans[2] = {0, 0};
	while(n--) {
		int size;
		std::cin >> size;
		std::vector<int> a(size);
		for(int i = 0; i < size; i++) {
			std::cin >> a[i];
		}
		int l = 0, r = size-1;
		while(l < r) {
			ans[0] += a[l++];
			ans[1] += a[r--];
		}
		if(l == r) {
			middle.push_back(a[l]);
		}
	}
	std::sort(middle.rbegin(), middle.rend());
	for(int i = 0; i < (int) middle.size(); i++) {
		ans[i % 2] += middle[i];
	}
	std::cout << ans[0] << ' ' << ans[1] << '\n';
}