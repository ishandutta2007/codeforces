#include<bits/stdc++.h>
using namespace std;
const int N(10001);
long long a[N], b[N];
long long dp[2][N];
int main() {
	int n, c;
	cin >> n >> c;
	for(int i(0); i < n; i++) {
		cin >> a[i];
	}
	for(int i(0); i < n; i++) {
		cin >> b[i];
	}
	dp[1][0] = 0;
	for(int i(0); i < n; i++) {
		for(int j(0); j <= i + 1; j++) {
			dp[i & 1][j] = 1e18;
		}
		for(int j(0); j <= i; j++) {
			dp[i & 1][j + 1] = min(dp[i & 1][j + 1], dp[i & 1 ^ 1][j] + b[i]);
			dp[i & 1][j] = min(dp[i & 1][j], dp[i & 1 ^ 1][j] + a[i] + (long long)c * j);
		}
	}
	long long ans(1e18);
	for(int i(0); i <= n; i++) {
		ans = min(ans, dp[n & 1 ^ 1][i]);
	}
	cout << ans << endl;
}