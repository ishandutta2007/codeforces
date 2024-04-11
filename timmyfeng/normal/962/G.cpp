#include <bits/stdc++.h> 
using namespace std;

const int MX = 15000;

int par[MX], sz[MX], cnt;

struct inter {
    int side, key, id, orient;    
};

bool operator<(inter a, inter b) {
    return make_tuple(a.side, a.key) < make_tuple(b.side, b.key);
}

int find(int a) {
	if (par[a] != a) {
		par[a] = find(par[a]);
	}
	return par[a];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[a] > sz[b]) {
		swap(a, b);
	}
	par[a] = b;
	sz[b] += sz[a];
	++cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int lb, ub, rb, db, n;
	cin >> lb >> ub >> rb >> db >> n;
	vector<pair<int, int>> pts(n);
	for (auto& i : pts) {
		cin >> i.first >> i.second;
	}

	iota(par, par + n, 0);
	fill(sz, sz + n, 1);

	int cur = 0;
	int ray = 0;
	bool link = false;
	vector<inter> edge;
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;

		int u = max(pts[i].second, pts[j].second);
		int d = min(pts[i].second, pts[j].second);
		int l = min(pts[i].first, pts[j].first);
		int r = max(pts[i].first, pts[j].first);

		if (l == r) {
			ray += (l >= rb && db >= d && db < u);

			if (l <= lb || l >= rb || u <= db || d >= ub)
				continue;

			if (pts[i].second == u) {
				if (u >= ub) {
					edge.push_back({1, -l, cur, true});
					++cur;
				}
				if (d <= db) {
					edge.push_back({3, l, cur, false});
				}
				++cur;
			} else {
				if (d <= db) {
					edge.push_back({3, l, cur, true});
					++cur;
				}
				if (u >= ub) {
					edge.push_back({1, -l, cur, false});
				}
				++cur;
			}

			if (cur >= 2) {
				unite(cur - 1, cur - 2);
			} else {
				link = true;
			}
		} else {
			if (u <= db || u >= ub || r <= lb || l >= rb)
				continue;

			if (pts[i].first == l) {
				if (l <= lb) {
					edge.push_back({2, -u, cur, true});
					++cur;
				}
				if (r >= rb) {
					edge.push_back({0, u, cur, false});
				}
				++cur;
			} else {
				if (r >= rb) {
					edge.push_back({0, u, cur, true});
					++cur;
				}
				if (l <= lb) {
					edge.push_back({2, -u, cur, false});
				}
				++cur;
			}

			if (cur >= 2) {
				unite(cur - 1, cur - 2);
			} else {
				link = true;
			}
		}
	}

	if (link) {
		unite(cur - 1, 0);
	}

	if (!edge.empty()) {
		sort(edge.begin(), edge.end());
		if (edge[0].orient) {
			rotate(edge.begin(), edge.begin() + 1, edge.end());
		}
		for (int i = 0; i < (int)edge.size(); i += 2) {
			unite(edge[i].id, edge[i + 1].id);
		}
	}

	cout << (cur ? cur - cnt : ray % 2) << '\n';
}