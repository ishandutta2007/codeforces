#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll, ll> del[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x1, y1, x2, y2, n;
	string s;
	cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

	for (int i = 0; i < n; ++i) {
		if (i) {
			del[i] = del[i - 1];
		}
		if (s[i] == 'U') {
			++del[i].second;
		} else if (s[i] == 'D') {
			--del[i].second;
		} else if (s[i] == 'L') {
			--del[i].first;
		} else {
			++del[i].first;
		}
	}
	
	ll lo = 0, hi = 1e18;
	while (lo < hi) {
		ll mi = (lo + hi) / 2;
		int ndx = (mi - 1 + n) % n;
		ll resx = x1 + del[ndx].first + del[n - 1].first * ((mi - 1) / n);
		ll resy = y1 + del[ndx].second + del[n - 1].second * ((mi - 1) / n);
		ll dist = abs(x2 - resx) + abs(y2 - resy);
		if (dist <= mi) {
			hi = mi;
		} else {
			lo = mi + 1;
		}
	}
	cout << (lo >= 1e18 ? -1 : lo) << '\n';
}