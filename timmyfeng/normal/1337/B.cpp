#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, n, m;
	cin >> x >> n >> m;
	while (n && x > x / 2 + 10) {
		--n;
		x = x / 2 + 10;
	}
	cout << (x <= m * 10 ? "YES" : "NO") << '\n';
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