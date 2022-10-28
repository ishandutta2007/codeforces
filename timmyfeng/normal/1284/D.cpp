#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e5 + 1;

mt19937_64 rng(uint64_t(new char));

ll hsh[MX];

vector<ll> get_res(vector<tuple<int, int, int>>& pts) {
	sort(pts.begin(), pts.end());

	ll cur = 0;
	int pre = 0;
	vector<ll> res;
	for (auto [x, type, i] : pts) {
		if (type) {
			if (!pre) {
				res.push_back(cur);
			}
			cur ^= hsh[i];
		} else {
			cur ^= hsh[i];
		}
		pre = type;
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<tuple<int, int, int>> pts1, pts2;
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pts1.emplace_back(a, 0, i);
		pts1.emplace_back(b, 1, i);
		pts2.emplace_back(c, 0, i);
		pts2.emplace_back(d, 1, i);
		hsh[i] = rng();
	}

	cout << (get_res(pts1) == get_res(pts2) ? "YES" : "NO") << '\n';
}