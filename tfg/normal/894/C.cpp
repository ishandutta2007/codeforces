#include <iostream>

int a[2020];

int main() {
	int m;
	std::cin >> m;
	bool valid = true;
	for(int i = 0; i < m ; i++) {
		std::cin >> a[i];
		valid = valid && a[i] % a[0] == 0;
	}
	if(valid) {
		std::cout << 2 * m + 1 << '\n';
		for(int i = 0; i < m; i++) {
			std::cout << a[0] << ' ' << a[i] << ' ';
		}
		std::cout << a[0] << '\n';
	} else {
		std::cout << "-1\n";
	}
}