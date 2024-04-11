#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector<int> a(n), b(m);
	for (auto& i : a) {
		cin >> i;
		i += ta;
	}
	for (auto& i : b) {
		cin >> i;
	}

	long long ans = 0;
	if (n <= k) {
		cout << -1 << "\n";
		return 0;
	}

	for (int i = 0; i <= k; ++i) {
		int ndx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (ndx + k - i >= m) {
			cout << -1 << "\n";
			return 0;
		}
		ans = max(ans, 0LL + b[ndx + k - i] + tb);
	}
	cout << ans << "\n";
}