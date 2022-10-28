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
		ll ans = 0;
		while (n >= k) {
			ans += n - n / k * k + 1;
			n /= k;
		}
		cout << ans + n << '\n';
	}
}