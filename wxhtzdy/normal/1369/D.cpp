#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7, M = 2e7 + 50;

long long dp[M];

void compute() {
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 4;
	for (int i = 3; i < M; i++) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		if (i % 3 == 2) {
			dp[i] += 4;
		}
		dp[i] %= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	compute();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n - 1] << endl;
	}
	return 0;
}