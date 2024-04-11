#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::vector<int> a;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = 0; j < 4; j++) {
			int t;
			std::cin >> t;
			sum += t;
		}
		a.push_back(sum);
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] <= a[0]) {
			ans++;
		}
	}
	std::cout << n - ans << std::endl;
}