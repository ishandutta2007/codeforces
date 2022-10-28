#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}

	if (n % 2 && a[n / 2] != b[n / 2]) {
		cout << "No" << '\n';
		return;
	}

	multiset<array<int, 2>> pairs_a;
	for (int i = 0; i < n; ++i) {
		pairs_a.insert({a[i], a[n - 1 - i]});
	}

	multiset<array<int, 2>> pairs_b;
	for (int i = 0; i < n; ++i) {
		pairs_b.insert({b[i], b[n - 1 - i]});
	}

	cout << (pairs_a == pairs_b ? "Yes" : "No") << '\n';
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