#include <iostream>

int getCost(char a, char b) {
	if(a > b) {
		std::swap(a, b);
	}
	return std::min(b - a, (26 + a - b) % 26);
}

int main() {
	int n, p;
	std::cin >> n >> p;
	std::string str;
	std::cin >> str;
	p--;
	p = std::min(p, n - p - 1);
	int l = n;
	int r = 0;
	int cost = 0;
	for(int i = 0; i < n / 2; i++) {
		int cur = getCost(str[i], str[n - i - 1]);
		if(cur > 0) {
			l = std::min(l, i);
			r = std::max(r, i);
			cost += cur;
		}
	}
	if(cost == 0) {

	} else if(p >= r) {
		cost += p - l;
	} else if(p <= l) {
		cost += r - p;
	} else {
		cost += std::min(p - l, r - p) + r - l;
	}
	std::cout << cost << '\n';
}