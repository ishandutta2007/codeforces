#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using Vi = vector<int>;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define tem template<class t, class u, class ...w> auto
#define pri(x,y,z) tem operator<<(t& o, u a)->decltype(z,o) { o << *x; y; z; return o << x[1]; }
pri("{}",, a.print())
pri("()",, o << a.x << ", " << a.y)
pri("[]", auto d=""; for (auto i : a) (o << d << i, d = ", "), all(a))
void DD(...) {}
tem DD(t s, u a, w... k) {
    for (int b = 1; cerr << *s++, *s && *s - b*44;) b += 2 / (*s*2 - 81);
    cerr << ": " << a; DD(s, k...);
}
#ifdef LOC
#define deb(...) DD("[,\b :] "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

// 0 = outer face vertex
// 1-n = cell vertices
// >n = other faces

// for cells:
// 012
// 7x3
// 654

struct FAU {
	Vi G;
	FAU(int n = 0) : G(n, -1) {}
	int find(int i) { return G[i] < 0 ? i : G[i] = find(G[i]); }
	bool join(int i, int j) {
		i = find(i); j = find(j);
		if (i == j) return 0;
		if (G[i] > G[j]) swap(i, j);
		G[i] += G[j]; G[j] = i;
		return 1;
	}
};

vector<bool> cell, outer, seen;
vector<Vi> edges;
vector<array<int, 8>> neigh;
priority_queue<int> que;
FAU dsu;

void dfsConnected(int v) {
	if (v == -1 || seen[v] || !cell[v]) return;
	seen[v] = 1;
	each(e, neigh[v]) dfsConnected(e);
}

void dfsOuter(int v) {
	if (cell[v]) return que.push(v);
	if (outer[v]) return;
	outer[v] = 1;
	each(e, edges[v]) dfsOuter(e);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);

	int n, t;
	cin >> n >> t;

	vector<Pii> elems(n);
	int minX = INT_MAX, minY = INT_MAX;
	int maxX = INT_MIN, maxY = INT_MIN;

	each(e, elems) {
		cin >> e.x >> e.y;
		minX = min(minX, e.x);
		minY = min(minY, e.y);
		maxX = max(maxX, e.x);
		maxY = max(maxY, e.y);
	}

	int C = maxX-minX+1;
	int R = maxY-minY+1;

	if (R > n+5 || C > n+5) {
		cout << "NO\n";
		return 0;
	}

	vector<vector<Pii>> cols(C);

	rep(i, 0, n) {
		auto& e = elems[i];
		e.x -= minX;
		e.y -= minY;
		cols[e.x].pb({e.y, i+1});
	}

	cell.resize(n+1, 1);
	cell[0] = 0;

	each(vec, cols) {
		sort(all(vec));
		int s = sz(vec);
		rep(i, 0, s) {
			int prv = (i > 0 ? vec[i-1].x+1 : 0);
			if (prv != vec[i].x) {
				vec.pb({prv, sz(cell)});
				cell.pb(0);
			}
		}
		int prv = (s > 0 ? vec[s-1].x+1 : 0);
		if (prv < R) {
			vec.pb({prv, sz(cell)});
			cell.pb(0);
		}
		sort(all(vec));
	}

	auto vertexAt = [&](int x, int y) {
		if (x < 0 || x >= C || y < 0 || y >= R) return 0;
		auto it = --upper_bound(all(cols[x]), y, [](int l, Pii r) { return l < r.x; });
		return it->y;
	};

	dsu = {sz(cell)};
	outer.resize(sz(cell));
	edges.resize(sz(cell));
	neigh.resize(sz(cell), {-1,-1,-1,-1,-1,-1,-1,-1});

	rep(x, 0, C) {
		rep(i, 0, sz(cols[x])) {
			auto& cur = cols[x][i];
			int nxtY = (i+1 < sz(cols[x]) ? cols[x][i+1].x : R);

			auto &N = neigh[cur.y];
			auto &E = edges[cur.y];

			if (cell[cur.y]) {
				N[0] = vertexAt(x-1, cur.x+1);
				N[1] = vertexAt(x, cur.x+1);
				N[2] = vertexAt(x+1, cur.x+1);
				N[3] = vertexAt(x+1, cur.x);
				N[4] = vertexAt(x+1, cur.x-1);
				N[5] = vertexAt(x, cur.x-1);
				N[6] = vertexAt(x-1, cur.x-1);
				N[7] = vertexAt(x-1, cur.x);
				E = {N[1], N[3], N[5], N[7]};
			} else {
				E.pb(vertexAt(x, cur.x-1));
				E.pb(vertexAt(x, nxtY));
				if (x > 0) {
					auto it = --upper_bound(all(cols[x-1]), cur.x, [](int l, Pii r) { return l < r.x; });
					while (it != cols[x-1].end() && it->x < nxtY) {
						E.pb(it->y);
						it++;
					}
				} else {
					E.pb(0);
				}
				if (x+1 < C) {
					auto it = --upper_bound(all(cols[x+1]), cur.x, [](int l, Pii r) { return l < r.x; });
					while (it != cols[x+1].end() && it->x < nxtY) {
						E.pb(it->y);
						it++;
					}
				} else {
					E.pb(0);
				}
			}

			each(u, E) if (u == 0) {
				edges[0].pb(cur.y);
				break;
			}
		}
	}

	seen.resize(sz(edges));
	dfsConnected(1);

	rep(i, 0, n) {
		if (!seen[i+1]) {
			cout << "NO\n";
			return 0;
		}
	}

	rep(i, 0, sz(cell)) if (!cell[i]) {
		each(e, edges[i]) if (!cell[e]) {
			dsu.join(i, e);
		}
	}

	dfsOuter(0);
	Vi ans;

	while (!que.empty()) {
		int v = que.top();
		que.pop();
		if (!cell[v]) continue;

		auto &N = neigh[v];
		bool good = 0;

		for (int i = 1; i < 8; i += 2) {
			if (outer[N[i]]) {
				good = 1;
				break;
			}
		}

		if (!good) continue;

		for (int i = 1; i < 8; i += 2) {
			int a = N[i];
			if (cell[a]) continue;
			a = dsu.find(a);
			for (int j = i+2; j < 8; j += 2) {
				int b = N[j];
				if (cell[b]) continue;
				b = dsu.find(b);
				if (a != b) continue;
				int cnt = 0;
				for (int k = i; k != j; k = (k+1)%8) {
					if (cell[N[k]]) {
						cnt++;
						break;
					}
				}
				for (int k = j; k != i; k = (k+1)%8) {
					if (cell[N[k]]) {
						cnt++;
						break;
					}
				}
				if (cnt == 2) {
					good = 0;
					break;
				}
			}
			if (!good) break;
		}

		if (good) {
			ans.pb(v);
			cell[v] = 0;
			dfsOuter(v);
			each(e, edges[v]) if (!cell[e]) {
				dsu.join(v, e);
			}

			for (int j = 0; j < 8; j += 2) {
				if (cell[N[j]]) {
					que.push(N[j]);
				}
			}
		}
	}

	cout << "YES\n";
	reverse(all(ans));
	each(a, ans) cout << a << '\n';
    return 0;
}