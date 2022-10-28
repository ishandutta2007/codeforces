#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end(), greater<int>());

		ll cur = 0;
		int ans = 0;
		for (; ans < n; ++ans) {
			cur += a[ans];
			if (cur < (ll)x * (ans + 1)) break;
		}
		cout << ans << '\n';
	}
}