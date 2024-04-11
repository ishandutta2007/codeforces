#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 5000 + 1;
const int INF = 1e9;

bitset<MX> dp[MX];
int a[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	ll v;
	cin >> n >> k >> v;

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	dp[0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (dp[i][j]) {
				dp[i + 1][j] = true;
				dp[i + 1][(j + a[i]) % k] = true;
			}
		}
	}

	if (sum < v || !dp[n][v % k]) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';

		int s = -1;
		int t = -1;
		for (int i = n; i; --i) {
			if (dp[i - 1][(v % k + k) % k]) {
				if (t == -1) {
					t = i;
				} else {
					cout << INF << ' ' << i << ' ' << t << '\n';
				}
			} else {
				if (s == -1) {
					s = i;
				} else {
					cout << INF << ' ' << i << ' ' << s << '\n';
				}
				v -= a[i - 1];
			}
		}

		if (t == -1) {
			t = 1;
		}
		if (s == -1) {
			s = 1;
		}
		
		if (v < 0) {
			cout << -v / k << ' ' << s << ' ' << t << '\n';
		} else if (v > 0) {
			cout << v / k << ' ' << t << ' ' << s << '\n';
		}
	}
}