#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 1010;
	std::vector<int> sum(ms, 0);
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	for(int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		std::swap(a, b);
		int wtf = str[i] - '0';
		sum[0] += wtf;
		for(int j = a; j < ms; j += b) {
			sum[j] -= wtf;
			wtf ^= 1;
			sum[j] += wtf;
		}
	}
	int ans = sum[0];
	for(int i = 1; i < ms; i++) {
		sum[i] += sum[i-1];
		ans = std::max(ans, sum[i]);
	}
	std::cout << ans << '\n';
}