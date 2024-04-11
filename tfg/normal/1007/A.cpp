#include <iostream>
#include <vector>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::map<int, int> freq;
	std::cin >> n;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		mx = std::max(mx, ++freq[t]);
	}
	std::cout << n - mx << std::endl;
}