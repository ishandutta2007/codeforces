#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 52;
const ll INF = 2e18;

ll _fact[MX], dp[MX];
ll* fact = _fact + 1;
int pos[MX];

ll add(ll a, ll b) {
	ll res = a + b;
	return res < INF ? res : INF;
}

ll mul(ll a, ll b) {
	return b > INF / a ? INF : a * b;
}

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	--k;
	
	if (dp[n] <= k) {
		cout << -1 << '\n';
		return;
	}

	memset(pos, -1, sizeof pos);
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int len = j - i + 1;
			ll cnt = mul(fact[len - 2], dp[n - j]);

			if (cnt <= k) {
				k -= cnt;
				continue;
			}

			cout << j << ' ';
			pos[j] = i;
			for (int x = i + 1; x <= j; ++x) {
				int skip = x;
				if (x != j) {
					while (pos[skip] != -1) {
						skip = pos[skip];	
					}
				}

				for (int y = i; y < j; ++y) {
					if (pos[y] != -1 || y == skip)
						continue;

					ll cur = mul(fact[j - x - 1], dp[n - j]);
					if (cur <= k) {
						k -= cur;
						continue;
					}

					cout << y << ' ';
					pos[y] = x;
					break;
				}
			}
			i += len - 1;
			break;
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[-1] = fact[0] = 1;
	for (int i = 1; i < MX - 1; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}

	dp[0] = 1;
	for (int i = 1; i < MX; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = add(dp[i], mul(fact[j - 2], dp[i - j]));
		}
	}

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}