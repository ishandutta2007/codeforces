#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		ll n, m, k;
		cin >> n >> m >> k;
		if (n > m) {
			swap(n, m);
		}
		if (k < m) {
			cout << -1 << '\n';
		} else if ((n + m) % 2) {
			cout << k - 1 << '\n';
		} else if ((k - m) % 2) {
			cout << k - 2 << '\n';
		} else {
			cout << k << '\n';
		}
	}
}