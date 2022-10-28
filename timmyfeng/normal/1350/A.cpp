#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		bool ok = false;
		for (ll i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				cout << n + i + k + k - 2 << '\n';
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << n + n + k + k - 2 << '\n';
		}
	}
}