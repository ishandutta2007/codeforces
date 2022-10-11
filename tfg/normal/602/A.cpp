#include <iostream>

typedef long long ll;

ll read() {
	int n, b;
	std::cin >> n >> b;
	ll ans = 0;
	while(n--) {
		ll temp;
		std::cin >> temp;
		ans = ans * b + temp;
	}
	return ans;
}

int main() {
	ll a, b;
	a = read();
	b = read();
	//std::cout << a << ", " << b << "\n";
	if(a > b) {
		std::cout << ">\n";
	} else if(a < b) {
		std::cout << "<\n";
	} else {
		std::cout << "=\n";
	}
}