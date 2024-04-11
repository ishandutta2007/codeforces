#include<bits/stdc++.h>
using namespace std;
const int N(111111), inf(2e9);
int dp[N], a[N];
int main() {
	int n;
	cin >> n;
	for(int i(1); i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = 1.5e9;
	fill(dp, dp + n + 2, inf);
	dp[1] = 0;
	for(int i(1); i <= n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 20);
		int x(lower_bound(a + 1, a + n + 2, a[i] + 90) - a);
		dp[x] = min(dp[x], dp[i] + 50);
		x = lower_bound(a + 1, a + n + 2, a[i] + 1440) - a;
		dp[x] = min(dp[x], dp[i] + 120);
	}
	for(int i(n); i >= 1; i--) 
		dp[i] = min(dp[i], dp[i + 1]);
	for(int i(1); i <= n; i++) {
		cout << dp[i + 1] - dp[i] << endl;
	}
}