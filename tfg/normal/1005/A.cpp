#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> ans;
	int last = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] == last + 1) {
			last++;
		} else {
			ans.push_back(last);
			last = a[i];
		}
	}
	ans.push_back(last);
	std::cout << ans.size() << std::endl;
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}