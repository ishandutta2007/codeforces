#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;
	
	vector<ll> dp(n + k + 1, 1e18);
	deque<pair<ll, int>> mono;
	mono.emplace_back(0, 0);
	dp[0] = 0;
	for (int i = 1; i <= n + k; ++i) {
		while (mono.front().second < i - 2 * k - 1) {
			mono.pop_front();
		}

		if (i > k && s[i - k - 1] == '1') {
			dp[i] = min(dp[i], mono.front().first + i - k);
		}
		dp[i] = min(dp[i], dp[i - 1] + i);

		while (!mono.empty() && dp[i] < mono.back().first) {
			mono.pop_back();
		}
		mono.emplace_back(dp[i], i);
	}
	cout << *min_element(dp.begin() + n, dp.end()) << '\n';
}