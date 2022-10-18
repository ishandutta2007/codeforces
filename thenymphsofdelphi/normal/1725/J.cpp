#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 1e5 + 5;

int n, h[N], d[N], ans, sum;
vector<pair<int, int>> adj[N];

inline int get(vector<pair<int, int>> &vc, int c, int u) {
	int res = 0;
	for (int i = 0; i < (int) vc.size() && c; i++) {
		if (vc[i].second != u)
			res += vc[i].first, c --;
	}
	return res;
}

void pre_dfs(int u, int p) {
	vector<pair<int, int>> vc;
	for (auto [v, w] : adj[u]) if (v != p) {
		pre_dfs(v, u);
		vc.emplace_back(h[v] + w, v);
		d[u] = max(d[u], d[v]);
	}
	sort(vc.rbegin(), vc.rend());
	h[u] = get(vc, 1, -1);
	d[u] = max(d[u], get(vc, 2, -1));
}

void solve(int u, int p) {
	vector<pair<int, int>> vc, vd;

	for (auto [v, w] : adj[u]) {
		vd.emplace_back(d[v], v);
		vc.emplace_back(h[v] + w, v);
	}

	// cout << "SOLVE " << u << endl;

	sort(vc.rbegin(), vc.rend());
	sort(vd.rbegin(), vd.rend());

	ans = max(ans, get(vc, 4, -1));

	for (auto [v, w] : adj[u]) if (v != p) {
		int hu = h[u], du = d[u];
		d[u] = max(get(vd, 1, v), get(vc, 2, v));
		h[u] = get(vc, 1, v);

		// cout << "reroot " << u << " -> " << v << endl;

		ans = max(ans, d[u] + d[v] + w * 2);
		solve(v, u);

		d[u] = du, h[u] = hu;
	}
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w, sum += w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	pre_dfs(1, 0);
	solve(1, 0);

	cout << sum * 2 - ans << '\n';
}