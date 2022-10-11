#include <iostream>
#include <vector>

const int ms = 1010;

bool np[ms];

int main() {
	int n;
	std::cin >> n;
	std::vector<int> ans;
	for(int i = 2; i <= n; i++) {
		if(np[i]) {
			continue;
		}
		int x = n;
		int cur = 1;
		while(x >= i) {
			cur *= i;
			x /= i;
			ans.push_back(cur);
		}
		for(int j = i + i; j <= n; j += i) {
			np[j] = true;
		}
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}