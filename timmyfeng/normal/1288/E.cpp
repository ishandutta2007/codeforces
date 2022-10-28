#include <bits/stdc++.h>
using namespace std;

const int MAG = 800;
const int MX = 3e5 + 1;

int a[2 * MX], freq[MX], ans[MX];
vector<tuple<int, int, int>> req;
vector<int> pos[MX];
bool cnt[MX];

void mo() {
	sort(req.begin(), req.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) {
		if (get<0>(a) / MAG == get<0>(b) / MAG)
			return get<1>(a) < get<1>(b);
		return get<0>(a) < get<0>(b);
	});

	int res = 0, i = 0, j = -1;
	for (auto [l, r, k] : req) {
		for ( ; j < r; ++j) {
			res += (!freq[a[j + 1]]);
			++freq[a[j + 1]];
		}
		for ( ; j > r; --j) {
			res -= (freq[a[j]] == 1);
			--freq[a[j]];
		}
		for ( ; i > l; --i) {
			res += (!freq[a[i - 1]]);
			++freq[a[i - 1]];
		}
		for ( ; i < l; ++i) {
			res -= (freq[a[i]] == 1);
			--freq[a[i]];
		}
		ans[k] = max(ans[k], res);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	m += n;
	for (int i = 0; i < m; ++i) {
		if (i < n) {
			a[i] = n - i;
		} else {
			cin >> a[i];
			cnt[a[i]] = true;
		}
		pos[a[i]].push_back(i);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)pos[i].size() - 1; ++j) {
			req.emplace_back(pos[i][j] + 1, pos[i][j + 1] - 1, i);
		}
		req.emplace_back(pos[i].back() + 1, m - 1, i);
	}

	mo();
	for (int i = 1; i <= n; ++i) {
		cout << (cnt[i] ? 1 : i) << ' ' << ans[i] + 1 << '\n';
	}
}