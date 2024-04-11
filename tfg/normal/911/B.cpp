#include <iostream>

int a, b;

int can(int x) {
	if(a < x || b < x) {
		return 0;
	} else {
		return a / x + b / x;
	}
}

int main() {
	int n;
	std::cin >> n >> a >> b;
	int l = 0, r = 1e7;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(can(mid) >= n) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << '\n';
}