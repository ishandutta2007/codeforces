#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int n = str.size();
	for(int i = 0; i + 1 < n; i++) {
		if((str[i] - '0') % 2 == 0 && str[i] < str.back()) {
			std::swap(str[i], str.back());
			std::cout << str << std::endl;
			return 0;
		}
	}
	for(int i = n - 2; i >= 0; i--) {
		if((str[i] - '0') % 2 == 0) {
			std::swap(str[i], str.back());
			std::cout << str << std::endl;
			return 0;
		}
	}
	std::cout << "-1\n";
}