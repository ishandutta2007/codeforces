#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int N = 2001;

int n, a[N];
long long dp[N][N];

int main() {
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(len, 2, n)
		rep(l, 1, n - len + 1) {
			int r = l + len - 1;
			dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + a[r] - a[l];
		}
	cout << dp[1][n] << "\n";
	return 0;
}