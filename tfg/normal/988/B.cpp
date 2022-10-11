#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::string> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end(), [](const std::string &a, const std::string &b) -> bool { return a.size() < b.size(); });
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l].size() == a[r].size()) {
			if(a[r] != a[l]) {
				std::cout << "NO\n";
				return 0;
			}
			r++;
		}
		if(r < n) {
			bool valid = false;
			for(int i = 0; i + a[l].size() <= a[r].size(); i++) {
				valid = valid || a[r].substr(i, a[l].size()) == a[l];
			}
			if(!valid) {
				std::cout << "NO\n";
				return 0;
			}
		}
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << std::endl;
	}
}