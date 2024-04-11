#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> good;
	map<ll, ll> val;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		if (val[a[i]]) {
			good.push_back(a[i]);
		}
		val[a[i]] += b;
	}

	ll ans = 0;
	for (auto i : val) {
		bool ok = false;
		for (auto j : good) {
			ok |= ((i.first & j) == i.first);
		}
		if (ok) {
			ans += i.second;
		}
	}
	cout << ans << "\n";
}