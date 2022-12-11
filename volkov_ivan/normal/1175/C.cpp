#include <iostream>
#define int long long

using namespace std;

const int INF = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res = INF, ans = 0;
	for (int i = 0; i + k < n; i++) {
		int cur = a[i + k] - a[i];
		if (cur < res) {
			res = cur;
			ans = (a[i + k] + a[i]) / 2;
		}
	}
	cout << ans << "\n";
}

signed main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}