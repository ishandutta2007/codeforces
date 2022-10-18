#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<tuple<int, int, int>> e;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		e.emplace_back(z, x, y);
	}
	sort(e.begin(), e.end());

	vector<tuple<int, int, int>> mst;
	int last_mst = 0;
	DSU d(n);
	for (auto [z, x, y]: e) {
		if (d.same(x, y)) continue;
		last_mst = z;
		mst.emplace_back(z, x, y);
		d.merge(x, y);
	}

	if (last_mst <= k) {
		int ans = 1000000000;
		for (auto [z, x, y]: e) {
			ans = min(ans, abs(z - k));
		}
		cout << ans << '\n';
	} else {
		int ans = 0;
		for (auto [z, x, y]: mst) {
			if (z > k) ans += z-k;
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}