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
		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (a % k) {
				++mp[a % k];
			}
		}

		long long ans = 0;
		for (auto& i : mp) {
			ans = max(ans, 1LL * i.second * k - i.first + 1);
		}
		cout << ans << "\n";
	}
}