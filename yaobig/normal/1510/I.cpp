#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ld randDouble(ld a, ld b) {
	return uniform_real_distribution<ld>(a, b)(rng);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	ld mult = 0.2; // sqrt(log(n) / m);
	// E[fails] <= (1 + mult) min_fails + ln N / mult

	vector<ld> lws(n, 1);
	for (int ind = 0; ind < m; ++ind) {
		string off;
		cin >> off;

		ld w0 = 0, w1 = 0;
		for (int i = 0; i < n; ++i) {
			if (off[i] == '0') w0 += lws[i];
			else w1 += lws[i];
		}
		
		if (randDouble(0, w0 + w1) < w0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}

		char ans;
		cin >> ans;
		for (int i = 0; i < n; ++i) {
			if (off[i] != ans) lws[i] *= 1 - mult;
		}
	}
}