#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5;

ll a[MX], b[MX];
vector<pair<ll, ll>> pq[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	ll lo = 0, hi = 5e13;
	while (lo < hi) {
		ll mi = (lo + hi) / 2;
		fill(pq, pq + k, vector<pair<ll, ll>>());
		for (int i = 0; i < n; ++i) {
			pq[min(a[i] / b[i], k - 1)].emplace_back(a[i], b[i]);
		}

		bool ok = true;
		int mn = 0;
		for (int i = 0; i < k; ++i) {
			while (pq[mn].empty()) {
				++mn;
			}
			if (mn < i) {
				ok = false;
				break;
			}
			ll x, y;
			tie(x, y) = pq[mn].back();
			pq[mn].pop_back();
			x += mi;
			pq[min(x / y, k - 1)].emplace_back(x, y);
		}

		if (ok) {
			hi = mi;
		} else {
			lo = mi + 1;
		}
	}

	cout << (lo == 5e13 ? -1 : lo) << '\n';
}