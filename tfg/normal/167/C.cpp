#include <iostream>

typedef long long ll;

bool solve(ll a, ll b) {
	if(a < b) std::swap(a, b);
	//std::cout << "(" << a << ", " << b << ")\n";
	if(b == 0) return false;
	else if(a - b < b) return !solve(b, a % b);
	else {
		ll nim;
		ll n = a / b;
		if(b % 2 == 1) {
			nim = n % 2;
			if(nim == 0) nim = 2;
		} else {
			nim = n % (b + 1);
			if(nim == 0) nim = 3;
			else nim = (nim + 1) % 2 + 1;
		}
		if(nim == 1) return !solve(b, a % b);
		else return true;
	}
}

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		ll a, b;
		std::cin >> a >> b;
		if(solve(a, b)) {
			std::cout << "First\n";
		} else {
			std::cout << "Second\n";
		}
	}
}