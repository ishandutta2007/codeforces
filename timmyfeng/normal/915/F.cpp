#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e6 + 1;

array<int, 2> vals[MX];
int par[MX], sz[MX], n;
vector<int> adj[MX];
bool vstd[MX];

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
}

ll calc() {
	fill(vstd + 1, vstd + n + 1, false);
	fill(sz + 1, sz + n + 1, 1);
	iota(par + 1, par + n + 1, 1);

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int cur = 1;
		for (auto c : adj[vals[i][1]]) {
			if (vstd[c]) {
				int chd = sz[find(c)];
				unite(vals[i][1], c);
				res += (ll)cur * chd * vals[i][0];
				cur += chd;
			}
		}
		vstd[vals[i][1]] = true;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> vals[i][0];
		vals[i][1] = i + 1;
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	sort(vals, vals + n);
	ll ans = calc();
	reverse(vals, vals + n);
	ans -= calc();
	cout << ans << '\n';
}