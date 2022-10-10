#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long L = 1;
	for(int i = 1; i <= 16; i++) {
		L = lcm(i, L);
	}
	std::vector<long long> val(17, 0);
	for(int i = 1; i <= 16; i++) {
		int j = 0;
		int k = 1;
		while(1) {
			j += i;
			while(k * k * k * k < j) k++;
			if(k * k * k * k == j) break;
		}
		val[i] = L + j;
		//std::cout << val[i] << '\n';
	}
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
		int x;
		std::cin >> x;
		std::cout << ((i + j) % 2 == 0 ? L : val[x]) << (j + 1 == m ? '\n' : ' ');
	}
}