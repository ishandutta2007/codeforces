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
	}
	int mx = *max_element(a.begin(), a.end());
	int ans = 0;
	int len = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == mx) {
			ans = max(ans, ++len);
		} else {
			len = 0;
		}
	}
	cout << ans << '\n';
}