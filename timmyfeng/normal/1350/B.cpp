#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 1;

int a[MX], dp[MX];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	fill_n(dp, n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = i * 2; j <= n; j += i) {
			if (a[i] < a[j]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}
	cout << *max_element(dp, dp + n + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}