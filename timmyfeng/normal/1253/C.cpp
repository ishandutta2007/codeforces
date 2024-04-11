#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (auto& i : x) {
		cin >> i;
	}
	sort(x.begin(), x.end());

	vector<long long> dp(n);
	for (int i = 0; i < n; ++i) {
		dp[i] += x[i];
		if (i - m >= 0) {
			dp[i] += dp[i - m];
		}
	}

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += dp[i];
		cout << sum << ' ';
	}
}