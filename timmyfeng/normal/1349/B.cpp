
#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 1;

int a[MX];

bool calc(int n, int k) {
	int mn = 1e9, pre = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= k) {
			cur += 1;
		} else if (a[i] < k) {
			cur -= 1;
		}
		if (cur > mn)
			return true;
		mn = min(mn, pre);
		pre = cur;
	}
	return false;
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (!count(a, a + n, k)) {
		cout << "NO" << '\n';
		return;
	}
	if (n == 1) {
		cout << (a[0] == k ? "YES" : "NO") << '\n';
		return;
	}
	
	bool ok = calc(n, k);
	reverse(a, a + n);
	ok |= calc(n, k);
	cout << (ok ? "YES" : "NO") << '\n';
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