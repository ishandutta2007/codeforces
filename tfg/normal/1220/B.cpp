#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;

int n;
int a[ms][ms];
int b[ms];

bool test(int x) {
	//std::cout << "testing " << x << '\n';
	b[0] = x;
	for(int i = 1; i < n; i++) {
		if(a[i][0] % x == 0) {
			b[i] = a[i][0] / x;
		} else {
			return false;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i][j] != (long long) b[i] * b[j] || a[i][j] != a[j][i]) {
				return false;
			}
		}
	}
	return true;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	int g = 0;
	for(int i = 0; i < n; i++) {
		g = gcd(g, a[0][i]);
	}
	for(int i = 1; i * i <= g; i++) {
		if(g % i == 0) {
			if(test(i)) {
				for(int j = 0; j < n; j++) {
					std::cout << b[j] << (j + 1 == n ? '\n' : ' ');
				}
				return 0;
			} else if(test(g/i)) {
				for(int j = 0; j < n; j++) {
					std::cout << b[j] << (j + 1 == n ? '\n' : ' ');
				}
				return 0;
			}
		}
	}
}