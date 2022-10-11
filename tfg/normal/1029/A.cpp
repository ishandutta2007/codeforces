#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::string str;
	std::cin >> n >> k >> str;
	int border = 0;
	for(int i = 1; i < n; i++) {
		if(str.substr(0, i) == str.substr(n - i, i)) {
			border = i;
		}
	}
	for(int i = 1; i < k; i++) {
		str += str.substr(border, n - border);
	}
	std::cout << str << std::endl;
}