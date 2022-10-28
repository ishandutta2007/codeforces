#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e5;

int n, a, r, m, h[MX];

ll calc(int tgt) {
	ll pos = 0, neg = 0;
	for (int i = 0; i < n; ++i) {
		if (h[i] > tgt) {
			pos += h[i] - tgt;
		} else {
			neg += tgt - h[i];
		}
	}
	return pos > neg ? (pos - neg) * r + neg * m : (neg - pos) * a + pos * m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> r >> m;
	m = min(m, a + r);
	for (int i = 0;i < n; ++i) {
		cin >> h[i];
	}

	int lb = 0, rb = 1e9;
	while (lb < rb) {
		int mb = (lb + rb) / 2;
		if (calc(mb) >= calc(mb + 1)) {
			lb = mb + 1;
		} else {
			rb = mb;
		}
	}
	cout << calc(lb) << '\n';
}