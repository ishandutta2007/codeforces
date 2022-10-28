#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end());

		vector<int> w(m);
		for (auto& i : w) {
			cin >> i;
		}
		sort(w.rbegin(), w.rend());

		int cur = 0;
		long long ans = 0;
		for (int i = 0; i < m; ++i) {
			if (w[i] > 1) {
				ans += a[cur];
			}
			cur += w[i] - 1;
		}
		for (int i = 0; i < m; ++i, ++cur) {
			if (w[i] == 1) {
				ans += 2 * a[cur];
			} else {
				ans += a[cur];
			}
		}
		cout << ans << "\n";
	}
}