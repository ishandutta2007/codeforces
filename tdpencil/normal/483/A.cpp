
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll l, r;

ll gcd(ll x, ll y) {
	if(y)
		return gcd(y,x%y);
	return x;
}
void solve() {
	cin >> l >> r;

	if(r-l<2) {
		cout << -1 << "\n";
	} else {
		for(ll i = l; i <= r; i++) {
			for(ll j = l; j <= r; ++j) {
				for(ll k = l; k <= r; ++k) {
					if(i < j && j < k && i < k) {
						if(gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1) {
							cout << i << " " << j << " " << k;
							cout << "\n";
							return;
						}
					}
				}
			}
		}

		cout << -1 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	//cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}