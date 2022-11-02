#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ask(ll b, ll e) {
	cout << "? " << b+1 << ' ' << e << endl;
	ll ret; cin >> ret;
	return ret;
}

void run() {
	ll n; cin >> n;
	ll b = 1, e = n+1;

	while (b+1 < e) {
		ll m = (b+e) / 2;
		(ask(0, m) > 0 ? e : b) = m;
	}

	ll i = b - 1;
	ll j = i + ask(i, n) - ask(i+1, n) + 1;
	ll k = j + ask(j, n) - ask(j+1, n) + 1;
	cout << "! " << i+1 << ' ' << j+1 << ' ' << k << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	int t; cin >> t;
	while (t--) run();
	return 0;
}