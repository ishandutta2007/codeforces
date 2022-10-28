#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
        cin.tie(0);
	string s;
	cin >> s;
	for (auto i : s) {
		if (i == 'w' || i == 'm') {
			cout << 0 << '\n';
			return 0;
		}
	}
	vector<int> dp(s.size() + 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= (int)s.size(); ++i) {
		dp[i] = dp[i - 1];
		if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n')) {
			(dp[i] += dp[i - 2]) %= MOD;
		}
	}
	cout << dp[(int)s.size()] << '\n';
}