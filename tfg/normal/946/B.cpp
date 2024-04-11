#include <iostream>

typedef long long ll;

int main() {
	ll a, b;
	std::cin >> a >> b;
	while(1) {
		if(a == 0 || b == 0) break;
		if(a >= 2 * b) {
			a = a % (2 * b);
		} else if(b >= 2 * a) {
			b = b % (2 * a);
		} else {
			break;
		}
	}
	std::cout << a << ' ' << b << '\n';
}