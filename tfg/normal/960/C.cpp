#include <iostream>
#include <vector>

typedef long long ll;

const int ms = 200;
const ll gap = 2e9;

ll dp[ms];
ll sum[ms];

int main() {
	dp[0] = 1;
	for(int i = 1; i < ms; i++) {
		dp[i] = 2 * dp[i - 1];
	}
	std::vector<ll> ans;
	ll x, d;
	std::cin >> x >> d;
	int off = 1;
	while(x > 0) {
		int got = 1;
		while(dp[got + 1] - 1 <= x) got++;
		x -= dp[got] - 1;
		for(int i = 0; i < got; i++) {
			ans.push_back(off * gap);
		}
		off++;
	}

	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}