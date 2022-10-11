#include <iostream>
#include <vector>
#include <cassert>

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a, b;
	for(int i = 1; i < n; i++) {
		a.push_back(i);
		b.push_back(i + 1);
		m--;
	}
	for(int i = 1; i <= n && m > 0; i++) {
		for(int j = i + 2; j <= n && m > 0; j++) {
			if(gcd(i, j) == 1) {
				a.push_back(i);
				b.push_back(j);
				m--;
			}
		}
	}
	if(m != 0) {
		std::cout << "Impossible\n";
	} else {
		std::cout << "Possible\n";
		for(int i = 0; i < a.size(); i++) {
			std::cout << a[i] << ' ' << b[i] << std::endl;
		}
	}
}