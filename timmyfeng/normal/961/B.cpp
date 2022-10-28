#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n), t(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : t) {
		cin >> i;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += t[i] * a[i];
	}

	int mx = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		if (i >= k && !t[i - k]) {
			cur -= a[i - k];
		}
		if (!t[i]) {
			cur += a[i];
		}
		mx = max(mx, cur);
	}
	cout << ans + mx << '\n';
}