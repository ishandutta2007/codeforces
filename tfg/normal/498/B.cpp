#include <iostream>
#include <iomanip>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, t;
	std::cin >> n >> t;
	std::vector<long double> dp(t + 1, 0);
	std::vector<long double> trans;
	dp[0] = 1;
	long double ans = 0;
	for(int i = 0; i < n; i++) {
		int p;
		std::cin >> p;
		int size;
		std::cin >> size;
		long double hit = p / 100.0;
		long double ratio = 1;
		for(int j = 1; j < size; j++) {
			ratio *= 1 - hit;
		}
		trans.assign(t + 1, 0);
		long double sum = dp[0];
		for(int j = 1; j <= t; j++) {
			if(j >= size) {
				sum -= ratio * dp[j - size];
			}
			trans[j] = sum * hit;
			sum = sum * (1 - hit) + dp[j];
		}
		for(int j = 0; j + size <= t; j++) {
			trans[j + size] += ratio * dp[j];
		}
		dp.swap(trans);
		for(int j = 0; j <= t; j++) {
			ans += dp[j];
			//std::cout << (double) dp[j] << (j == t ? '\n' : ' ');
		}
	}
	std::cout << std::fixed << std::setprecision(20);
	std::cout << (double) ans << std::endl;
}