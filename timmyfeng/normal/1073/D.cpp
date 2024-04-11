#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

int n, a[MX];
ll ft[MX];

void upd(int a, int val) {
	for ( ; a <= n; a += a & -a) {
		ft[a] += val;
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

	ll t;
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		upd(i, a[i]);
	}

	ll ans = 0;
	for (int i = n; i; --i) {
		ll cur = qry(n);
		ans += i * (t / cur);
		t %= cur;
		int lb = 1, rb = n;
		while (lb < rb) {
			int mb = (lb + rb) / 2;
			if (qry(mb) <= t) {
				lb = mb + 1;
			} else {
				rb = mb;
			}
		}
		upd(lb, -a[lb]);
	}
	cout << ans << '\n';
}