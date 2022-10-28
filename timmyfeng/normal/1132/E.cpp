#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int LCM = 840;

ll dp[9][LCM];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll w;
	cin >> w;
	for (int i = 1; i <= 8; ++i) {
		ll cnt;
		cin >> cnt;
		for (int j = 0; j < LCM; ++j) {
			ll add = min((w - dp[i - 1][j]) / i, cnt);
			for (ll k = max(0LL, add - LCM / i + 1); k <= add; ++k) {
				ll res = dp[i - 1][j] + k * i; 
				dp[i][res % LCM] = max(dp[i][res % LCM], res);
			}
		}
	}
	cout << *max_element(dp[8], dp[8] + LCM) << '\n';
}