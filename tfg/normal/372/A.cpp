#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> a;
	int n;
	std::cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	auto can = [](const std::vector<int> &kan, int k) {
		for(int i = 0; i < k; i++) {
			//std::cout << "comparing " << kan[i] << ", " << kan[kan.size() - k + i] << std::endl;
			if(kan[i] * 2 > kan[kan.size() - k + i]) {
				return false;
			}
		}
		return true;
	};
	int l = 0, r = n / 2;
	//std::cout << l << ", " << r << std::endl;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(can(a, mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << n - l << std::endl;
}