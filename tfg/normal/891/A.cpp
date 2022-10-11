#include <iostream>

const int ms = 2020;

int gcd(int a, int b) {
	if(!b) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int a[ms];

int main() {
	int n;
	std::cin >> n;
	int ones = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] == 1) {
			ones++;
		}
	}
	if(ones) {
		std::cout << n - ones << '\n';
		return 0;
	}
	int ans = 10 * n + 1;
	for(int i = 0; i < n; i++) {
		int p = i;
		int g = a[i];
		while(g != 1 && p > 0) {
			g = gcd(g, a[p - 1]);
			p--;
		}
		if(g == 1) {
			ans = std::min(ans, n - 1 + i - p);
		}
		p = i;
		g = a[i];
		while(g != 1 && p + 1 < n) {
			g = gcd(g, a[p + 1]);
			p++;
		}
		if(g == 1) {
			ans = std::min(ans, n - 1 + p - i);
		}
	}
	if(ans == 10 * n + 1) {
		ans = -1;
	}
	std::cout << ans << '\n';
}