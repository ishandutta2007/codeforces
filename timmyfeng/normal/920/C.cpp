#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
		--i;
	}
	string s;
	cin >> s;

	vector<int> col(n);
	for (int i = 1; i < n; ++i) {
		if (s[i - 1] == '1') {
			col[i] = col[i - 1];
		} else {
			col[i] = col[i - 1] + 1;
		}
	}

	bool ok = true;
	for (int i = 0; i < n; ++i) {
		ok &= (col[i] == col[a[i]]);
	}
	cout << (ok ? "YES" : "NO") << '\n';
}