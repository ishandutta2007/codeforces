#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e6 + 1;

int n, k, l, cnt[MX];
bitset<MX> a;
ll dp[MX];
string s;

void calc(int lam) {
	dp[0] = cnt[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] + a[i - 1];
		cnt[i] = cnt[i - 1];
		if (i >= l && lam + dp[i - l] < dp[i]) {
			dp[i] = lam + dp[i - l];
			cnt[i] = 1 + cnt[i - l];
		}
	}
}

int solve() {
	int lb = 0, rb = n;
	while (lb < rb) {
		int mb = (lb + rb) / 2;
		calc(mb);
		if (cnt[n] > k) {
			lb = mb + 1;
		} else {
			rb = mb;
		}
	}
	calc(lb);
	return dp[n] - (ll)k * lb;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> l >> s;
	for (int i = 0; i < n; ++i) {
		a[i] = (s[i] >= 'a');
	}

	if ((ll)k * l >= n) {
		cout << 0 << '\n';
		return 0;
	}

	int ans = solve();
	a.flip();
	ans = min(solve(), ans);

	cout << ans << '\n';
}