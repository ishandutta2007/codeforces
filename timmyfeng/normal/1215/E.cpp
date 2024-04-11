#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 4e5;

int a[MX];
ll dp[1 << 20];
ll op[20][20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (i == j) continue;
			int cnt = 0;
			for (int k = 0; k < n; ++k) {
				if (a[k] == i) {
					++cnt;
				} else if (a[k] == j) {
					op[i][j] += cnt;
				}
			}
		}
	}

	for (int ma = 1; ma < (1 << 20); ++ma) {
		dp[ma] = 1e18;
		for (int i = 0; i < 20; ++i) {
			if (ma & (1 << i)) {
				ll sum = 0;
				for (int j = 0; j < 20; ++j) {
					if (i == j || !(ma & (1 << j))) continue;
					sum += op[i][j];
				}
				dp[ma] = min(dp[ma], dp[ma ^ (1 << i)] + sum);
			}
		}
	}
	cout << dp[(1 << 20) - 1] << '\n';
}