#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

long long fexp(long long x, long long e) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	const int me = 20;
	const int ms = 1 << me;
	std::vector<int> a(ms, 0);
	while(n--) {
		int x;
		std::cin >> x;
		a[x]++;
	}
	for(int len = 1; len < ms; len += len) {
		for(int i = 0; i < ms; i += len+len) {
			for(int j = 0; j < len; j++) {
				a[i+j] = (a[i+j] + a[i+j+len]) % MOD;
			}
		}
	}
	for(auto &i : a) {
		i = (int) fexp(2, i);
	}
	for(int len = 1; len < ms; len += len) {
		for(int i = 0; i < ms; i += len+len) {
			for(int j = 0; j < len; j++) {
				a[i+j] = (a[i+j] - a[i+j+len] + MOD) % MOD;
			}
		}
	}
	std::cout << a[0] << '\n';
}