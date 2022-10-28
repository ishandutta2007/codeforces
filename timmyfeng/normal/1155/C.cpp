#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	vector<ll> p(m);
	for (auto& i : p) {
		cin >> i;
	}

	ll gcd = 0;
	for (int i = 1; i < n; ++i) {
		gcd = __gcd(gcd, a[i] - a[i - 1]);
	}

	for (int i = 0; i < m; ++i) {
		if (gcd % p[i] == 0) {
			cout << "YES" << '\n';
			cout << a[0] << ' ' << i + 1 << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}