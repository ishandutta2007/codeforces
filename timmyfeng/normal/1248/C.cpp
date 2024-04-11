#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long solve(int n) {
	vector<long long> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if (i - 2 >= 0) {
			(dp[i] += dp[i - 2]) %= MOD;
		}
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cout << ((solve(n) * 2 % MOD) + ((solve(m) - 1 + MOD) * 2 % MOD)) % MOD <<'\n';
}