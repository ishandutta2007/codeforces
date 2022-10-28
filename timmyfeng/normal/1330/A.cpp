#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<bool> seen(300);
	while (n--) {
		int a;
		cin >> a;
		seen[a] = true;
	}
	for (int i = 1; i < 300; ++i ){
		if (seen[i]) continue;
		if (!x) {
			cout << i - 1 << '\n';
			return;;
		}
		seen[i] = true;
		--x;
	}
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