#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(k);
		for (auto& i : a) {
			cin >> i;
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int res = 1e9;
			for (auto j : a) {
				res = min(res, abs(j - i) + 1);
			}
			ans = max(ans, res);
		}
		cout << ans << '\n';
	}
}