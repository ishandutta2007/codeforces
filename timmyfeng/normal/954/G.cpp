#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 5e5 + 2;

ll ft[MX];

void upd(int a, ll b) {
	for ( ; a < MX; a += a & -a) {
		ft[a] += b;
	}
}

ll qry(int a) {
	ll res = 0;
	for ( ; a; a -= a & -a) {
		res += ft[a];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r;
	ll k;
	cin >> n >> r >> k;

	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	ll lb = 0, rb = 2e18;
	while (lb < rb) {
		ll mb = (lb + rb + 1) / 2;

		memset(ft, 0, sizeof ft);
		for (int i = 1; i <= n; ++i) {
			upd(i, a[i - 1]);
		}
		
		ll res = 0;
		for (int i = 1; i <= n && res <= k; ++i) {
			ll cur = qry(min(n, i + r)) - qry(max(1, i - r) - 1);
			if (cur < mb) {
				res += mb - cur;
				upd(min(n, i + r), mb - cur);
			}
		}

		if (res <= k) {
			lb = mb;
		} else {
			rb = mb - 1;
		}
	}
	cout << lb << '\n';
}