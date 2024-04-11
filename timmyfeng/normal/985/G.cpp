#include <bits/stdc++.h> 
using namespace std;

using ull = unsigned long long;
const int MX = 2e5;
const int MAG = 500;

vector<int> adj_g[MX], adj_l[MX];
int heavy[MX], u[MX], v[MX];
bitset<MX> has[MAG * 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	ull a, b, c;
	cin >> n >> m >> a >> b >> c;
	vector<tuple<int, int, int>> pts;
	for (int i = 0; i < m; ++i) {
		cin >> u[i] >> v[i];
		if (u[i] > v[i]) {
			swap(u[i], v[i]);
		}
		pts.emplace_back(u[i], 1, i);
		pts.emplace_back(v[i], 0, i);
		adj_g[u[i]].push_back(v[i]);
		adj_l[v[i]].push_back(u[i]);
	}

	sort(pts.begin(), pts.end());
	for (int i = 0, k = 0; i < n; ++i) {
		int sz = adj_g[i].size() + adj_l[i].size();
		sort(adj_g[i].begin(), adj_g[i].end());
		sort(adj_l[i].begin(), adj_l[i].end());

		if (sz > MAG) {
			heavy[i] = ++k;
			for (auto j : adj_g[i]) {
				has[k][j] = 1;
			}
			for (auto j : adj_l[i]) {
				has[k][j] = 1;
			}
		}
	}

	// 
	ull ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += a * i * ((ull)(n - i - 1) * (n - i - 2) / 2);
		ans += b * i * ((ull)i * (n - i - 1));
		ans += c * i * ((ull)i * (i - 1) / 2);
	}

	// (i, j)
	ull cur = 0;
	int cnt = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < 2 * m && get<0>(pts[j]) < i) {
			if (!get<1>(pts[j])) {
				cur += a * u[get<2>(pts[j])] + b * v[get<2>(pts[j])];
				++cnt;
			}
			++j;
		}
		ans -= c * cnt * i + cur;
	}

	// (j, k)
	cur = 0;
	cnt = 0;
	for (int i = n - 1, j = 2 * m - 1; i >= 0; --i) {
		while (j >= 0 && get<0>(pts[j]) > i) {
			if (get<1>(pts[j])) {
				cur += b * u[get<2>(pts[j])] + c * v[get<2>(pts[j])];
				++cnt;
			}
			--j;
		}
		ans -= a * cnt * i + cur;
	}
	
	// (i, k)
	cur = 0;
	cnt = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < 2 * m && (get<0>(pts[j]) < i || (get<0>(pts[j]) == i && !get<1>(pts[j])))) {
			if (get<1>(pts[j])) {
				cur += a * u[get<2>(pts[j])] + c * v[get<2>(pts[j])];
				++cnt;
			} else {
				cur -= a * u[get<2>(pts[j])] + c * v[get<2>(pts[j])];
				--cnt;
			}
			++j;
		}
		ans -= cnt * b * i + cur;
	}

	// (i, j) + (i, k)
	for (int i = 0; i < n; ++i) {
		cur = 0;
		cnt = 0;
		for (auto j : adj_g[i]) {
			ans += cnt * (a * i + c * j) + cur;
			cur += b * j;
			++cnt;
		}
	}

	// (i, k) + (j, k)
	for (int i = 0; i < n; ++i) {
		cur = 0;
		cnt = 0;
		for (auto j : adj_l[i]) {
			ans += cnt * (b * j + c * i) + cur;
			cur += a * j;
			++cnt;
		}
	}

	// (i, j) + (j, k)
	for (int i = 0; i < n; ++i) {
		int sz_l = (int)adj_l[i].size();
		int sz_g = (int)adj_g[i].size();
		ans += b * sz_l * sz_g * i;
		for (auto j : adj_l[i]) {
			ans += a * sz_g * j;
		}
		for (auto j : adj_g[i]) {
			ans += c * sz_l * j;
		}
	}

	// all
	for (int i = 0; i < n; ++i) {
		if (heavy[i]) {
			for (int j = 0; j < m; ++j) {
				if (i >= u[j] || i >= v[j])
					continue;
				if (has[heavy[i]][u[j]] && has[heavy[i]][v[j]]) {
					ans -= a * i + b * u[j] + c * v[j];
				}
			}
		} else {
			for (auto j : adj_g[i]) {
				if (!heavy[j]) {
					has[0].reset();
					for (auto k : adj_l[j]) {
						has[0][k] = 1;
					}
					for (auto k : adj_g[j]) {
						has[0][k] = 1;
					}
				}
				for (auto k : adj_g[i]) {
					if (k >= j)
						break;
					if (has[heavy[j]][k]) {
						ans -= a * i + b * k + c * j;
					}
				}
			}
		}
	}
	cout << ans << '\n';
}