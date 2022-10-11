#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> lis(n);
	int c = 0;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		int idx = std::upper_bound(lis.begin(), lis.begin() + c, t) - lis.begin();
		lis[idx] = t;
		if(idx == c) c++;
	}
	std::cout << c << std::endl;
}