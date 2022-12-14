#include <iostream>
#include <vector>

int constexpr mulH = 60, mulMS = 12, bound = 12 * 60;

void processH(int& x) {
	x %= 12; x *= mulH;
}

void wrapBound(int& x) {
	x %= bound;
	if (x < 0) x += bound;
}

int main() {
	std::vector<int> hands (3);
	std::cin >> hands[0]; processH(hands[0]);
	std::cin >> hands[1]; hands[1] *= mulMS;
	std::cin >> hands[2]; hands[2] *= mulMS;
	int t1, t2; std::cin >> t1 >> t2; processH(t1); processH(t2);
	for (int i = 0; i < 3; ++i) {
		hands[i] -= t1; wrapBound(hands[i]);
	}
	t2 -= t1; wrapBound(t2);
	t1 = 0;

	for (int i = 0; i < 3; ++i) hands[i] = hands[i] < t2;
	for (int i = 1; i < 3; ++i) {
		if (hands[i] != hands[0]) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}