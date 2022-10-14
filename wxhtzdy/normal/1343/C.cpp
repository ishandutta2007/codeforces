#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> v;
		int tr = 0;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				tr = a[i];
				continue;
			}
			if ((a[i] >= 0 && a[i - 1] < 0) || (a[i] < 0 && a[i - 1] >= 0)) {
				v.push_back(tr);
				tr = a[i];
				ok = true;
			} else {
				tr = max(tr, a[i]);
				ok = false;
			}
		}
		v.push_back(tr);
		long long ans = 0;
		for (int i = 0; i < (int)v.size(); i++) {
			ans += v[i];
		}
		cout << ans << endl;
	}
	return 0;
}