#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		map<ll, int> m;
		for (ll i = 2; i * i <= n; ++i) {
			while (n % i == 0) {
				m[i]++;
				n /= i;
			}
		}
		if (n > 1) m[n]++;
		int mx = 0;
		for (auto [p, c] : m)
			mx = max(mx, c);
		vector<ll> ans(mx, 1);
		for (auto [p, c] : m) 
			for (int i = 1; i <= c; ++i)
				ans[mx - i] *= p;
		printf("%d\n", mx);
		for (auto x : ans)
			printf("%lld ", x);
		puts("");
	}
	return 0;
}