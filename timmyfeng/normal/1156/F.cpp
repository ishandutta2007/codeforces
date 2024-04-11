#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 5000;
const int M = (119 << 23) + 1;

ll dp[MX + 1][MX + 1], inv[MX + 1];
int freq[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		++freq[a];
	}

	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = M - M / i * inv[M % i] % M;
	}

	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i - 1][j - 1] * freq[i] % M * inv[n + 1 - j] % M;
			ans = (ans + dp[i][j] * (freq[i] - 1) % M * inv[n - j] % M) % M;
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
		}
	}
	cout << ans << '\n';
}