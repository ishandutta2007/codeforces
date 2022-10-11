#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(101, -1);
	std::vector<int> got;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		if(a[t] == -1) {
			a[t] = i;
			got.push_back(i + 1);
		}
	}
	if(got.size() >= k) {
		std::cout << "YES\n";
		for(int i = 0; i < k; i++) {
			std::cout << got[i] << (i + 1 == k ? '\n' : ' ');
		}
	} else {
		std::cout << "NO\n";
	}
}