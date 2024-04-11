#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e6;
using ll = long long;

ll ps[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	for (int i = b; i <= c; ++i) {
		int mn = i + a, mx = i + b;
		++ps[mn];
		--ps[mx + 1];
	}
	for (int i = 1; i < MX; ++i) {
		ps[i] += ps[i - 1];
	}
	for (int i = MX - 2; i >= 0; --i) {
		ps[i] += ps[i + 1];
	}

	ll ans = 0;
	for (int i = d; i >= c; --i) {
		ans += ps[i + 1];
	}
	cout << ans << '\n';
}