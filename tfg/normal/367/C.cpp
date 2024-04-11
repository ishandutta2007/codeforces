#include <iostream>
#include <algorithm>

typedef long long ll;

const int ms = 100100;

int f(int n) {
	if(n <= 0) {
		return 0;
	} else if(n == 1) {
		return 1;
	} else if(n == 2) {
		return 2;
	} else if(n % 2 == 1) {
		return n * (n - 1) / 2 + 1;
	} else {
		return n * (n - 1) / 2 + 1 + (n - 2) / 2;
	}
}

int cost[ms];

int main() {
	for(int i = 0; i < 20; i++) {
		//std::cout << f(i) << '\n';
	}
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int trash;
		std::cin >> trash;
		std::cin >> cost[i];
	}
	int got = 0;
	while(f(got + 1) <= n && got < m) {
		got++;
	}
	std::sort(cost, cost + m, std::greater<int>());
	ll ans = 0;
	for(int i = 0; i < got; i++) {
		ans += cost[i];
	}
	std::cout << ans << '\n';
}