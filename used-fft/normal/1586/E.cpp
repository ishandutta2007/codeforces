#include <bits/stdc++.h>
using namespace std;

const int Z = 3e5;

int n, m, q, d[Z] {1}, p[Z], w[Z], req;
vector<int> g[Z], h[Z], ans[Z];

void init(int u) {
	for(const int &v : h[u]) if(!d[v]) {
		d[v] = d[u] + 1;
		p[v] = u;
		g[u].push_back(v);
		init(v);
	}
}

void dfs(int u) {
	int diff = w[u], cnt {};
	for(const int &v : g[u]) {
		dfs(v);
		cnt += w[v];
	}

	if(w[u] && cnt) diff = min(diff, -(cnt - 1) / 2);	

	req += min(diff, w[u] -cnt / 2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;

	while(m--) {
		int u, v; cin >> u >> v;
		h[u-1].push_back(v-1);
		h[v-1].push_back(u-1);
	}
	init(0);

	cin >> q;

	for(int i = 0; i < q; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		vector<int> a;

		while(u != v) {
			if(d[u] > d[v]) {
				w[u] ^= 1;
				ans[i].push_back(u);
				u = p[u];
			} else {
				w[v] ^= 1;
				a.push_back(v);
				v = p[v];
			}
		}
		ans[i].push_back(u);
		for(int j = size(a); j--; ) ans[i].push_back(a[j]);
	}

	dfs(0);
	if(req) {
		cout << "NO\n" << req;
	} else {
		cout << "YES\n";
		for(int i = 0; i < q; ++i) {
			cout << size(ans[i]) << '\n';
			for(const int &u : ans[i]) cout << u+1 << ' ';
			cout << '\n';
		}
	}
}