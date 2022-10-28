#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> m >> n;
		ll ans = 0;
		int per = n % 2 == 0 ? 5 : (n % 5 == 0 ? 2 : 10);
		for (int i = 1; i < 10; ++i) {
			ll cur = 0;
			while (cur % 10 != i && cur < n * 10) {
				cur += n;
			}
			if (cur % 10 != i || cur > m) {
				continue;
			}
			ans += i * ((m - cur) / per / n + 1);
		}
		cout << ans << '\n';
	}
}