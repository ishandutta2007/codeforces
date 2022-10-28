#include <bits/stdc++.h>
using namespace std;

const int MX = 2e6 + 1;
const int M = 1e9 + 7;

int dp[MX];
bool chosen[MX];

int add(int a, int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 3; i < MX; ++i) {
		dp[i] = add(add(dp[i - 2], dp[i - 2]), dp[i - 1]);
		if (!chosen[i - 2] && !chosen[i - 1]) {
			dp[i] = add(dp[i], 4);
			chosen[i] = true;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}