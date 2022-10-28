#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int LOGN = 18;
const int MAG = 1e6;

int cnt_x[LOGN], cnt_y[LOGN], freq[1 << LOGN], sz;
ll pf[LOGN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, x, y;
	cin >> n >> x >> y;
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	if (y % x) {
		cout << 0 << '\n';
		return 0;
	}

	ll yy = y;
	for (ll i = 2; i * i <= yy && i <= MAG; ++i) {
		if (yy % i)
			continue;
		pf[sz] = i;
		while (yy % i == 0) {
			yy /= i;
			++cnt_y[sz];
		}
		++sz;
	}

	if (yy > 1) {
		ll lb = 0, rb = 1e9;
		while (lb < rb) {
			ll mb = (lb + rb) / 2;
			if (mb * mb < yy) {
				lb = mb + 1;
			} else {
				rb = mb;
			}
		}
		if (lb * lb == yy) {
			pf[sz] = lb;
			cnt_y[sz++] = 2;
			yy = 1;
		}
	}

	if (yy > 1) {
		vector<ll> pos = a;
		pos.push_back(x);
		for (auto i : pos) {
			ll g = __gcd(i, yy);
			if (g != 1 && g != yy) {
				pf[sz] = g;
				pf[sz + 1] = yy / g;
				cnt_y[sz++] = 1;
				cnt_y[sz++] = 1;
				yy = 1;
			}
		}

		if (yy > 1) {
			pf[sz] = yy;
			cnt_y[sz++] = 1;
		}
	}

	ll xx = x;
	for (int i = 0; i < sz; ++i) {
		while (xx % pf[i] == 0) {
			xx /= pf[i];
			++cnt_x[i];
		}
	}

	for (auto i : a) {
		if (i % x)
			continue;
		int mask = 0;
		for (int j = 0; j < sz; ++j) {
			int cnt = 0;
			while (i % pf[j] == 0) {
				i /= pf[j];
				++cnt;
			}
			mask |= (cnt > cnt_x[j]) << j;
		}
		++freq[mask];
	}

	for (int i = 0; i < sz; ++i) {
		for (int mask = 0; mask < (1 << sz); ++mask) {
			if (mask & (1 << i)) {
				freq[mask] += freq[mask ^ (1 << i)];
			}
		}
	}

	ll ans = 0;
	for (auto i : a) {
		if (y % i)
			continue;
		int mask = 0;
		for (int j = 0; j < sz; ++j) {
			int cnt = 0;
			while (i % pf[j] == 0) {
				i /= pf[j];
				++cnt;
			}
			mask |= (cnt == cnt_y[j] || cnt_x[j] == cnt_y[j]) << j;
		}
		ans += freq[mask];
	}
	cout << ans << '\n';
}