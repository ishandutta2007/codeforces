#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = (119 << 23) + 1;
const int MX = 3e5;

ll fact[MX + 1];

template <typename T>
ll solve(vector<T>& a) {
	ll res = 1;
	int len = 0;
	T prev;
	for (auto i : a) {
		if (i == prev) {
			++len;
		} else {
			res = res * fact[len] % M;
			len = 1;
			prev = i;
		}
	}
	res = res * fact[len] % M;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<pair<int, int>> p(n);
	for (int i = 0 ;i < n; ++i) {
		cin >> a[i] >> b[i];
		p[i] = {a[i], b[i]};
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = i * fact[i - 1] % M;
	}

	ll ans = (fact[n] - (solve(a) + solve(b)) % M + M) % M;
	sort(p.begin(), p.end());

	for (int i = 1; i < n; ++i) {
		if (p[i].second < p[i - 1].second) {
			cout << ans << '\n';
			return 0;
		}
	}
	cout << (ans + solve(p)) % M << '\n';
}