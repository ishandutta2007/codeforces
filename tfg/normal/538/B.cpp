#include <iostream>
#include <vector>

int f(int n) {
	if(n < 10) {
		return 1;
	} else {
		return (n % 10 ? 1 : 0) + 10 * f(n / 10);
	}
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> ans;
	while(n) {
		ans.push_back(f(n));
		n -= ans.back();
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}