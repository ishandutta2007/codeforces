#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<set<int>> s(n);
	for (int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		while (c--) {
			int a;
			cin >> a;
			s[i].insert(a);
		}
	}

	cout << "? " << n;
	for (int i = 1; i <= n; ++i) {
		cout << ' ' << i;
	}
	cout << endl;

	int mx;
	cin >> mx;

	int lb = 1, rb = n;
	while (lb < rb) {
		int mb = (lb + rb) / 2;
		cout << "? " << mb - lb + 1;
		for (int i = lb; i <= mb; ++i) {
			cout << ' ' << i;
		}
		cout << endl;

		int res;
		cin >> res;
		if (res < mx) {
			lb = mb + 1;
		} else {
			rb = mb;
		}
	}

	vector<int> ans(k);
	for (int i = 0; i < k; ++i) {
		if (!s[i].count(lb)) {
			ans[i] = mx;
		} else {
			cout << "? " << n - (int)s[i].size();
			for (int j = 1; j <= n; ++j) {
				if (!s[i].count(j)) {
					cout << ' ' << j;
				}
			}
			cout << endl;
			cin >> ans[i];
		}
	}

	cout << "! ";
	for (int i = 0; i < k; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;

	string correct;
	cin >> correct;
	if (correct != "Correct") {
		cout << "fu" << endl;
		exit(0);
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