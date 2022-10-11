#include <iostream>

int main() {
	int n, x;
	std::cin >> n >> x;
	int hmm = n - 1;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		hmm += t;
	}
	if(x == hmm) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}