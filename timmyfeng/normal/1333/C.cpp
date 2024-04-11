#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	ll cur = 0, ans = 0, mx = -1;
	map<ll, ll> prev;
	prev[0] = 0;
	for (int i = 0; i < n; ++i) {
		cur += a[i];
		if (prev.count(cur)) {
			mx = max(mx, prev[cur]);
		}
		ans += i - mx;
		prev[cur] = i + 1;
	}
	cout << ans << '\n';
}