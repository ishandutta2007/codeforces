#include <iostream>

int a[100100];
int b[100100];

int main() {
	int max = -1, freq = 0;
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = n - 1; i >= 0; i--) {
		b[i] = std::max(0, a[i + 1] - a[i] + 1);
		a[i] = std::max(a[i], a[i + 1]);
	}
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
	}
}