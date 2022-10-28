#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> c(n);
	vector<int> t(n);
	for (auto& i : c) {
		cin >> i;
	}
	for (auto& i : t) {
		cin >> i;
	}

	if (c[0] != t[0] || c.back() != t.back()) {
		cout << "No\n";
		return 0;
	}

	for (int i = 0; i + 1 < n; ++i) {
		c[i] -= c[i + 1];
		t[i] -= t[i + 1];
	}
	c.pop_back();
	t.pop_back();
	sort(c.begin(), c.end());
	sort(t.begin(), t.end());

	cout << (c == t ? "Yes" : "No") << "\n";
}