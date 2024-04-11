#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define vi vector<int>

using namespace std;

const int P = 1e9 + 7;

int t, n, m, dp[200001];

int main() {
	cin.tie(0);
	FOR(i, 9)
		dp[i] = 2;
	dp[9] = 3;
	dp[10] = 4;
	rep(i, 11, 200000)
		dp[i] = (dp[i - 10] + dp[i - 9]) % P;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		long long res = 0;
		while (n) {
			int x = n % 10;
			res += (10 - x > m ? 1 : dp[m - (10 - x)]);
			n /= 10;
		}
		cout << res % P << "\n";	
	}
	return 0;
}