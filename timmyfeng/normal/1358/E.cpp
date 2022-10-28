#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int m = (n + 1) / 2;
	vector<int> a(m);
	for (auto& i : a) {
		cin >> i;
	}
	int x;
	cin >> x;

	vector<ll> pre_min(m + 1);
	ll sum = 0;
	for (int i = 1; i <= m; ++i) {
		sum += x - a[i - 1];
		pre_min[i] = min(pre_min[i - 1], sum);
	}

	ll first = 0;
	for (auto i : a) {
		first += i;
	}

	for (int k = m; k <= n; ++k) {
		if (first > 0 && first + pre_min[n - k] > 0) {
			cout << k << '\n';
			return 0;
		}
		first += x;	
	}
	cout << -1 << '\n';
}