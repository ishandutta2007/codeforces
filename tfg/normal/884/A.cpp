#include <iostream>

int main() {
	int n, t;
	std::cin >> n >> t;
	for(int i = 1; i <= n; i++) {
		int hmm;
		std::cin >> hmm;
		t -= 86400 - hmm;
		if(t <= 0) {
			std::cout << i << '\n';
			return 0;
		}
	}
}