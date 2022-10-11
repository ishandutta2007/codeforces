#include <iostream>
#include <vector>

int main() {
	std::string str;
	std::cin >> str;
	int ans[3] = {0, -1237861, -1253123};
	int sum = 0;
	for(auto d : str) {
		int v = d - '0';
		sum = (sum + v) % 3;
		int bst = 0;
		for(int i = 0; i < 3; i++) {
			bst = std::max(bst, ans[i] + (i == sum ? 1 : 0));
		}
		ans[sum] = bst;
		//std::cout << "sum is " << sum << ", got (" << ans[0] << ", " << ans[1] << ", " << ans[2] << ")\n";
	}
	std::cout << std::max(ans[0], std::max(ans[1], ans[2])) << std::endl;
}