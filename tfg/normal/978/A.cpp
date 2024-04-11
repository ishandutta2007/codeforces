#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		int freq = 0;
		for(int j = i; j < n; j++) {
			freq += a[i] == a[j] ? 1 : 0;
		}
		if(freq == 1) {
			ans.push_back(a[i]);
		}
	}
	std::cout << ans.size() << std::endl;
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}