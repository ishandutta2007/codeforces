#include <iostream>
#include <vector>

typedef long long ll;

const int ms = 2e5;

std::vector<ll> divs[ms];

int main() {
	ll n, a, b;
	std::cin >> n >> a >> b;
	n *= 6;
	if(a * b >= n) {
		std::cout << a * b << '\n' << a << ' ' << b << '\n';
	} else if(a == 1) {
		std::cout << n << '\n' << 1 << ' ' << n << '\n';
	} else if(b == 1) {
		std::cout << n << '\n' << n << ' ' << 1 << '\n'; 
	} else {
		for(int i = 1; i < ms; i++) {
			for(int j = (-n % i + i) % i; j < ms; j += i) {
				divs[j].push_back(i);
				divs[j].push_back((n + j) / i);
			}
		}
		for(int i = 0; i < ms; i++) {
			for(auto d : divs[i]) {
				ll o = (n + i) / d;
				if(d >= a && o >= b) {
					std::cout << n + i << '\n' << d << ' ' << o << '\n';
					return 0;
				}
			}
		}
	}
}