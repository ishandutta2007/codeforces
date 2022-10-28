#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	for (auto& i : a) {
		cin >> i;
		sum += i;
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (auto& i : b) {
		cin >> i;
		sum -= i;
	}

	if (sum) {
		cout << -1 << '\n';
		return 0;
	}

	int i = 0, j = 0, ans = 0;
	ll sa = a[0], sb = b[0];
	while (true) {
		if (sa == sb) {
			++ans;
			if (i + 1 < n) {
				sa += a[++i];
			} else {
				break;
			}
		} else if (sa < sb) {
			sa += a[++i];
		} else {
			sb += b[++j];
		}
	}
	cout << ans << '\n';
}