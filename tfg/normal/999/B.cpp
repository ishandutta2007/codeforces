#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) {
			std::reverse(str.begin(), str.begin() + i);
		}
	}
	std::cout << str << std::endl;
}