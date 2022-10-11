#include <iostream>
#include <cstdio>

const int ms = 1001;

int freq[ms];

std::string get(int n, int r) {
	if(r == 0) {
		return "";
	} else {
		return get(n / 10, r - 1) + char('0' + n % 10);
	}
}

int main() {
	int n;
	std::cin >> n;
	long long ans = 0;
	for(int i = 0; i < 2 * n; i++) {
		//int a, b;
		//scanf("%d.%d", &a, &b);
		std::string kill_me;
		std::cin >> kill_me;
		int base = 1;
		int b = 0;
		for(int j = 0; j < 3; j++) {
			b += base * (kill_me[kill_me.size() - j - 1] - '0');
			base *= 10;
		}
		//std::cout << a << ' ' << b << '\n';
		freq[b]++;
		if(b > 0) {
			ans += b;
		}
	}
	int l = std::max(0, n - freq[0]);
	int r = std::min(n, 2 * n - freq[0]);
	long long tot = ans;
	ans = 1e18;
	for(int i = l; i <= r; i++) {
		ans = std::min(ans, std::max(tot - 1000 * i, -tot + 1000 * i));
	}
	std::cout << ans / 1000 << '.' << get(ans % 1000, 3) << '\n';
}