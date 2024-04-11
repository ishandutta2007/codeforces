#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::string a, b;
	std::cin >> a >> b;
	if(n < m) {
		a = std::string(m - n, '0') + a;
		n = m;
	} else if(m < n) {
		b = std::string(n - m, '0') + b;
		m = n;
	}
	long long ans = 0;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		if(b[i] == '1') {
			sum++;
		}
		ans = ans * 2 % MOD;
		if(a[i] == '1') {
			ans = (ans + sum) % MOD;
		}
	}
	std::cout << ans << std::endl;
}