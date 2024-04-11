#include <iostream>
#include <string>

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for(int j = 0; j < m; j++) {
			if(str[j] == '.') {
				std::cout << ((i + j) % 2 == 0 ? 'B' : 'W');
			} else {
				std::cout << '-';
			}
		}
		std::cout << '\n';
	}
}