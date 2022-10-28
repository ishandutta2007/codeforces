#include <bits/stdc++.h> 
using namespace std;

const int MX = 5000 + 1;
const int M = 1e9 + 7;

int cnt_r[MX], cnt_l[MX], s[MX];
vector<int> cows[MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		++cnt_r[s[i]];
	}

	for (int i = 0; i < m; ++i) {
		int f, h;
		cin >> f >> h;
		cows[f].push_back(h);
	}

	for (int i = 1; i <= n; ++i) {
		sort(cows[i].begin(), cows[i].end());
	}

	int ans1 = 0;
	int ans2 = 0;

	auto upd = [&](int exc) {
		int res = 0;
		int way = 1;
		for (int j = 1; j <= n; ++j) {
			int ndx_l = upper_bound(cows[j].begin(), cows[j].end(), cnt_l[j]) - cows[j].begin();
			int ndx_r = upper_bound(cows[j].begin(), cows[j].end(), cnt_r[j]) - cows[j].begin();
			if (!ndx_l && !ndx_r)
				continue;

			if (j == exc) {
				if (ndx_r >= ndx_l) {
					--ndx_r;
				}
				res += 1 + !!ndx_r;
				if (ndx_r) {
					way = mul(way, ndx_r);
				}
			} else if (!ndx_l || !ndx_r || (ndx_l == 1 && ndx_r == 1)) {
				++res;
				way = mul(way, ndx_l + ndx_r);
			} else {
				res += 2;
				way = mul(way, mul(min(ndx_l, ndx_r), max(ndx_l, ndx_r) - 1));
			}
		}

		if (res > ans1) {
			ans1 = res;
			ans2 = 0;
		}
		if (res == ans1) {
			ans2 = add(ans2, way);
		}
	};

	upd(0);
	for (int i = 0; i < n; ++i) {
		++cnt_l[s[i]];
		--cnt_r[s[i]];
		auto it = lower_bound(cows[s[i]].begin(), cows[s[i]].end(), cnt_l[s[i]]);
		if (it != cows[s[i]].end() && *it == cnt_l[s[i]]) {
			upd(s[i]);
		}
	}

	cout << ans1 << ' ' << ans2 << '\n';
}