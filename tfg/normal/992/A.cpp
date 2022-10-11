#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	bool zero = false;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		zero = zero || a[i] == 0;
	}
	std::sort(a.begin(), a.end());
	a.resize(std::unique(a.begin(), a.end()) - a.begin());
	std::cout << a.size() - (zero ? 1 : 0) << std::endl;
}