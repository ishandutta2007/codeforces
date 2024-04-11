#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 7;
vector <int> g[MAX_N];
int depth[MAX_N];
int cnt[MAX_N];
int only[MAX_N];
int prevv[MAX_N];
int mem[MAX_N];

void dfs0(int v, int dist, int d = 0, int pr = -1) {
	depth[v] = d;
	prevv[v] = pr;
	cnt[v] = 0;
	if (d == dist) {
		cnt[v] = 1;
		only[v] = v;
	}
	for (int u : g[v]) {
		if (u == pr) continue;
		dfs0(u, dist, d + 1, v);
		cnt[v] += cnt[u];
		if (cnt[u] != 0) only[v] = only[u];
	}
}

int get_dist(int v) {
	cout << "d " << v << endl;
	int x;
	cin >> x;
	return x;
}

int get_nxt(int v) {
	cout << "s " << v << endl;
	int x;
	cin >> x;
	return x;
}

int dfs(int v, int pr, int sz) {
	mem[depth[v]] = v;
	for (int u : g[v]) {
		if (u != pr && cnt[u] * 2 > sz) return dfs(u, v, sz);
	}
	return v;
}

int rec(int v, int x_depth) {
	int sz = cnt[v];
	if (sz == 1) return only[v];
	int maxi = 0;
	for (int u : g[v]) {
		if (u != prevv[v]) maxi = max(maxi, cnt[u]);
	}
	if (maxi * 2 <= sz) {
		int nxt = get_nxt(v);
		return rec(nxt, x_depth);
	}
	int new_v = dfs(v, prevv[v], sz);
	int v_d = depth[new_v];
	int dd = get_dist(new_v);
	int anc_depth = v_d - (dd - (x_depth - v_d)) / 2;
	int anc = mem[anc_depth];
	int nxt = get_nxt(anc);
	return rec(nxt, x_depth);
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	int dist = get_dist(1);
	dfs0(1, dist);
	int res = rec(1, dist);
	cout << "! " << res << endl;
	return 0;
}