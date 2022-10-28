#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int m = 2;
	while (m * (m + 1) / 2 <= n) {
		++m;
	}
	vector<int> stk;
	for ( ; m > 1; --m) {
		while (m * (m - 1) / 2 <= n) {
			stk.push_back(m);
			n -= m * (m - 1) / 2;
		}
	}
	cout << '1';
	int cnt = 0;
	while (!stk.empty()) {
		++cnt;
		cout << '3';
		while (stk.back() == cnt) {
			cout << '7';
			stk.pop_back();
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}