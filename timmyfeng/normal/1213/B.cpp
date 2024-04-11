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
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		int ans = 0, mn = 1e9;
		for (int i = n - 1; i >= 0; --i) {
			ans += (mn < a[i]);
			mn = min(mn, a[i]);
		}
		cout << ans << '\n';
	}
}