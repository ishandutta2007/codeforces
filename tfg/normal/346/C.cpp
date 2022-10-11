#include <iostream>
#include <map>

typedef long long ll;

const int ms = 1e6 + 10;

ll delta[ms];
int dp[ms];
int to[ms];

int main() {
	int n;
	std::cin >> n;
	std::map<int, int> freq;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		freq[t]++;
	}
	int l, r;
	std::cin >> r >> l;
	for(int i = l; i <= r; i++) {
		to[i - l] = i - l - 1;
	}
	ll cur = 0;
	to[r - l + 1] = 1e9;
	for(auto term : freq) {
		cur += (ll) r % term.first * term.second;
		for(ll i = l + (term.first - l % term.first) % term.first; i <= r + term.first; i += term.first) {
			if(i - term.first >= l) {
				to[std::min(r - l, (int)i - 1 - l)] = std::min(to[std::min(r - l, (int)i - 1 - l)], (int)i - term.first - l);
			}
			//std::cout << "for " << term.first << ", passing through " << i << "\n";
		}
	}
	for(int i = l; i <= r; i++) {
		dp[i - l] = 1e9;
	}
	dp[r - l] = 0;
	for(int i = r; i > l; i--) {
		//std::cout << "on " << i << ", to " << to[i - l] << ", cost is " << dp[i - l] << "\n";
		to[i - l] = std::min(to[i - l], to[i - l + 1]);
		dp[to[i - l]] = std::min(dp[to[i - l]], 1 + dp[i - l]);
		dp[i - 1 - l] = std::min(dp[i - 1 - l], dp[i - l] + 1);
		cur -= n;
		cur += delta[i - l];
	}
	std::cout << dp[0] << '\n';
}