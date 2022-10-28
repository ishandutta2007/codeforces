#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	if (n > m) {
		cout << 0 << '\n';
		return 0;
	}
	sort(a.begin(), a.end());
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			(ans *= a[j] - a[i]) %= m;
		}
	}
	cout << ans << '\n';
}