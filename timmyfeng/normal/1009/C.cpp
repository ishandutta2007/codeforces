#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);

	int n, m;
	cin >> n >> m;

	ll cur = 0;
	for (int i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		cur += a * n;
		if (b > 0) {
			cur += b * n * (n - 1) / 2;
		} else {
			ll n1 = n / 2 + 1, n2 = (n + 1) / 2;
			cur += b * n1 * (n1 - 1) / 2 + b * n2 * (n2 - 1) / 2;
		}
	}

	cout << (double) cur / n << '\n';
}