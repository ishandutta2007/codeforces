#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	string s, t;
	cin >> n >> m >> q >> s >> t;

	vector<int> ps(n + 1);
	for (int i = 1; i <= n; ++i) {
		ps[i] = ps[i - 1] + (s.substr(i - 1, m) == t);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		if (r - l + 1 < m) {
			cout << 0 << '\n';
		} else {
			cout << ps[r - m + 1] - ps[l - 1] << '\n';
		}
	}
}