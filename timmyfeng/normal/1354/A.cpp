#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a <= b) {
			cout << b << '\n';
		} else if (d >= c) {
			cout << -1 << '\n';
		} else {
			ll rep = (a - b - 1) / (c - d) + 1;
			cout << b + rep * c << '\n';
		}
	}
}