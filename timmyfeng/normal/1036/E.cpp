#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1000;

struct ln {
	ll a, b, c;
} seg[MX];

int ax[MX], bx[MX], ay[MX], by[MX];

pair<ll, ll> intersect(ln i, ln j) {
	ll det = i.a * j.b - i.b * j.a;
	ll resx = j.b * i.c - i.b * j.c;
	ll resy = i.a * j.c - j.a * i.c;
	if (!det || resx % det || resy % det) {
		return {1e9, 1e9};
	}
	return {resx / det, resy / det};
}

bool chk(pair<ll, ll> i, int j) {
	return i.first >= ax[j] && i.first <= bx[j] && i.second >= ay[j] && i.second <= by[j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
		seg[i].a = by[i] - ay[i];
		seg[i].b = ax[i] - bx[i];
		seg[i].c = seg[i].a * ax[i] + seg[i].b * ay[i];
		if (ax[i] > bx[i]) {
			swap(ax[i], bx[i]);
		}
		if (ay[i] > by[i]) {
			swap(ay[i], by[i]);
		}
		ans += 1 + __gcd(bx[i] - ax[i], by[i] - ay[i]);
	}

	map<pair<ll, ll>, int> mp;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			auto res = intersect(seg[i], seg[j]);
			if (chk(res, i) && chk(res, j)) {
				++mp[res];
			}
		}
	}

	map<int, int> comb;
	for (int i = 1; i <= n; ++i) {
		comb[i * (i - 1) / 2] = i;
	}

	for (auto i : mp) {
		ans -= comb[i.second] - 1;
	}
	cout << ans << '\n';
}