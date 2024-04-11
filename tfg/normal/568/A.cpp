#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool isPal(int x) {
	std::string str;
	do {
		str += char('0' + x % 10);
		x /= 10;
	} while(x);
	bool valid = true;
	for(int i = 0; i < (int) str.size(); i++) {
		valid = valid && str[i] == str[(int) str.size() - i - 1];
	}
	return valid;
}

const int ms = 10010000;

int isPrime[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i < ms; i++) {
		isPrime[i] = 1;
	}
	for(int i = 2; i < ms; i++) {
		if(!isPrime[i]) continue;
		for(int j = i + i; j < ms; j += i) {
			isPrime[j] = 0;
		}
	}
	int ans = 1;
	int pal = 1;
	long long p, q;
	std::cin >> p >> q;
	for(int i = 2; i < ms; i++) {
		if(isPal(i)) {
			pal++;
		}
		// pi <= p / q * pal
		// pi * q <= p * pal
		isPrime[i] += isPrime[i-1];
		if(isPrime[i] * q <= p * pal) {
			ans = i;
		}
	}
	std::cout << ans << '\n';
}