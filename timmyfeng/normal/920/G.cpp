#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e6 + 1;

int sieve[MX];

ll calc(ll a, vector<int>& divisors) {
	ll res = 0;
	int n = divisors.size();
	for (int i = 0; i < n; ++i) {
		if (__builtin_popcount(i) % 2) {
			res -= a / divisors[i];
		} else {
			res += a / divisors[i];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < MX; ++i) {
		if (sieve[i])
			continue;
		for (int j = i; j < MX; j += i) {
			if (!sieve[j]) {
				sieve[j] = i;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int x, p, k;
		cin >> x >> p >> k;

		vector<int> pf;
		while (p > 1) {
			if (pf.empty() || pf.back() != sieve[p]) {
				pf.push_back(sieve[p]);
			}
			p /= sieve[p];
		}

		int n = pf.size();
		vector<int> divisors(1 << n, 1);
		for (int i = 0; i < (1 << n); ++i) {
			for (int j = 0; j < n; ++j) {
				if (i & (1 << j)) {
					divisors[i] *= pf[j];
				}
			}
		}

		ll tgt = calc(x, divisors) + k;
		ll lb = x + 1;
		ll rb = 1e18;
		while (lb < rb) {
			ll mb = (lb + rb) / 2;
			if (calc(mb, divisors) < tgt) {
				lb = mb + 1;
			} else {
				rb = mb;
			}
		}
		cout << lb << '\n';
	}
}