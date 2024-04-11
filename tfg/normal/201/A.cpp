#include <iostream>

int main() {
	int n;
	std::cin >> n;
	if(n == 1) {
		std::cout << 1 << '\n';
	} else if(n == 3) {
		std::cout << 5 << '\n';
	}else {
		for(int i = 3; ; i++) {
			if(i % 2 == 0 && n % 4 != 0) {
				continue;
			}
			int can = 0;
			int last = 0;
			for(int j = 0; j < (i + 1) / 2 - (i % 2 == 0 ? 1 : 0); j++) {
				//std::cout << "got " << ((i + (j + 1) % 2) / 2) << "\n";
				can += 2 * ((i + (j + 1) % 2) / 2);
				last = ((i + (j + 1) % 2) / 2);
			}
			if(i % 2 == 1) {
				can -= last;
			}
			//std::cout << "for " << i << ", got " << can << '\n';
			if(can >= n) {
				std::cout << i << '\n';
				break;
			}
		}
	}
}