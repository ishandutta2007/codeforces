#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll lcm(ll a, ll b) {
	return a * b / __gcd(a,b);
}
ll solve(ll n, ll a, ll b) {
	ll res = (n / lcm(a, b) + 1) * b;
	if (n % lcm(a, b) < b) {
		res -= b - n % lcm(a, b) - 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;
		if (a > b) {
			swap(a, b);
		}
		while (q--) {
			ll l, r;
			cin >> l >> r;
			cout << r - l + 1 - (solve(r, a, b) - solve(l - 1, a, b)) << ' ';
		}
		cout << '\n';
	}
}