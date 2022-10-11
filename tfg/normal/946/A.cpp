#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int pos = 0, neg = 0;
	int min = 19298938;
	while(n--) {
		int t;
		std::cin >> t;
		if(t >= 0) {
			min = std::min(min, t);
			pos += t;
		} else {
			neg += t;
		}
	}
	std::cout << pos - neg << '\n';
}