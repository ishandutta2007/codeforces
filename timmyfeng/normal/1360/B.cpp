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
		sort(a.begin(), a.end());
		int ans = 1e9;
		for (int i = 0; i < n - 1; ++i) {
			ans = min(ans, a[i + 1] - a[i]);
		}
		cout << ans << '\n';
	}
}