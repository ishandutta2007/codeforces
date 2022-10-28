#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> b(n);
	for (auto& i : b) {
		cin >> i;
	}

	vector<int> a(n);
	for (int i = 1; i < n; ++i) {
		a.push_back(b[i] - b[i - 1] - 1);
	}
	sort(a.rbegin(), a.rend());

	int ans = b[n - 1] - b[0] + 1;
	for (int i = 0; i + 1 < k; ++i) {
		ans -= a[i];
	}
	cout << ans << "\n";
}