#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		ll ans = 0;
		ll len = 2;
		for (int i = 1; len / 2 <= n; ++i, len *= 2) {
			ans += i * ((n - len / 2) / len + 1);
		}
		cout << ans << '\n';
	}
}