#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int k, n, m;
		cin >> k >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		vector<int> ans;
		for (int i = 0, j = 0; i < n || j < m;) {
            if (j == m || (i < n && a[i] < b[j])) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
		}
		bool ok = true;
		for (int x : ans) {
            if (x == 0) k++;
            else {
                if (k < x) ok = false;
            }
		}
		if (!ok) {
			cout << -1 << '\n';
			continue;
		}
		for (int x : ans) {
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}