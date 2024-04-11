#include <bits/stdc++.h>
using namespace std;
#define int long long

const int LIM = 2e5+1, INF = 2e9;

struct UFDS{
	vector<int> e;
	int operator()(int u){
		return e[u] < 0 ? u : e[u] = (*this)(e[u]);
	}
	void operator()(int u, int v){
		u = (*this)(u), v = (*this)(v);
		if(u==v) return;
		if(e[u] > e[v]) swap(u, v);
		e[u] += e[v], e[v] = u;
	}
	void init(int n){ e.assign(n, -1); }
} uf;

int n, m, sum[LIM], res[LIM], id[LIM], same[LIM];

array<int, 3> q[LIM];

vector<array<int, 2>> g[LIM], g2[LIM];
vector<array<int, 3>> h;

int get(int v){
	return __builtin_popcount(v) & 1;
}

void add(int u, int v, int w){
	g2[u].push_back({v, w});
	g2[v].push_back({u, w});
}

void dfs(int u, int p){
	for(auto &[v, w] : g[u]){
		if(v == p) continue;
		if(w >= 0 && sum[u] >= 0)
			sum[v] = get(w) ^ sum[u];
		else
			sum[v] = -1;

		if(w >= 0)
			add(u, v, get(w));

		dfs(v, u);
	}
}

void dfs1(int u, int p){
	for(auto &[v, w] : g[u]){
		if(v == p) continue;

		if(w < 0) w = bool(res[u] ^ res[v]);

		sum[v] = w ^ sum[u];

		h.push_back({u, v, w});
		
		dfs1(v, u);
	}
}

int curr;

void dfs2(int u, int ext){
	id[u] = curr;
	same[u] = ext;
	for(auto &[v, w] : g2[u]){
		if(id[v]) continue;
		dfs2(v, ext ^ w);
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T;
	while(T--){
		cin >> n >> m;

		for(int i=1; i<=n; ++i){
			g[i].clear();
			g2[i].clear();
			sum[i] = res[i] = 0;
		}

		for(int i=1; i<n; ++i){
			int u, v, w;
			cin >> u >> v >> w;

			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}


		dfs(1, 0);

		bool ok = 1;

		for(int i=0; i<m; ++i){
			auto &[a, b, p] = q[i];
			cin >> a >> b >> p;

			add(a, b, p);
		}

		fill(id, id+n+1, 0);
		fill(same, same+n+1, 0);

		for(int i=1; i<=n; ++i){
			if(id[i]) continue;
			curr = i;
			dfs2(i, 0);
		}

		for(int u=1; u<=n; ++u){
			if(sum[u] >= 0)
				res[id[u]] = sum[u] ^ same[u];
		}

		for(int u=1; u<=n; ++u){
			res[u] = res[id[u]] ^ same[u];
		}

		fill(sum, sum+n+1, 0);

		h.clear();

		dfs1(1, 0);


		for(int i=0; i<m; ++i){
			auto &[a, b, p] = q[i];

			if(p != get(sum[a] ^ sum[b])) ok = 0;
		}

		if(ok){
			cout << "YES\n";
			for(auto &[u, v, w] : h){
				cout << u << ' ' << v << ' ' << w << '\n';
			}
		}else cout << "NO\n";
	}
}