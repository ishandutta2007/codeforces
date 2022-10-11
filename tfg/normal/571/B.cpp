#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

const int ms = 5050;

int a[300300];
long long dp[ms][ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	if(n <= m) {
		std::cout << "0\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	for(int i = 0; i < n; i++) {
		//std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
	int full = n % m;
	if(full == 0) {
		full = m;
	}
	int size = (n + m - 1) / m;
	int rest = m - full;
	//std::cout << "full size is " << size << ", got (" << full << ", " << rest << ")\n";
	for(int sum = 1; sum <= m; sum++) {
		for(int f = 0; f <= sum && f <= full; f++) {
			int r = sum - f;
			if(r > rest) {
				continue;
			}
			dp[f][r] = 1e18;
			int pos = f * size + r * (size - 1) - 1;
			//std::cout << "for (" << f << ", " << r << ") on pos " << pos << ", back full is " << pos - size + 1 << ", half is " << pos - size + 2 << "\n";
			if(f) {
				//std::cout << "first\n";
				dp[f][r] = std::min(dp[f][r], dp[f - 1][r] + (a[pos] - a[pos - size + 1]));
			}
			if(r) {
				//std::cout << "second\n";
				dp[f][r] = std::min(dp[f][r], dp[f][r - 1] + (a[pos] - a[pos - size + 2]));
			}
			//std::cout << "got " << dp[f][r] << "\n";
		}
	}
	std::cout << dp[full][rest] << '\n';
}