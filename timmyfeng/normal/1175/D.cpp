#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<ll> ss(n);
	for (int i = 0; i < n; ++i) {
		ss[i] = (i ? ss[i - 1] : 0) + a[n - 1 - i];
	}
	sort(ss.begin(), ss.end() - 1);
	reverse(ss.begin(), ss.end() - 1);

	ll ans = ss[n - 1];
	for (int i = 0; i < k - 1; ++i) {
		ans += ss[i];
	}
	cout << ans << '\n';
}