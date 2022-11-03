/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// rollback Union-Find
struct UnionFind {
    vector<int> par;
    stack<pair<int,int>> history;
    
    UnionFind() {}
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        history.emplace(x, par[x]);
        history.emplace(y, par[y]);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }

    // 1-step undo
    void undo() {
        for (int iter = 0; iter < 2; ++iter) {
            par[history.top().first] = history.top().second;
            history.pop();
        }
    }

    // erase history
    void snapshot() {
        while (!history.empty()) history.pop();
    }

    // all rollback
    void rollback() {
        while (!history.empty()) undo();
    }
};

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> c(n);
	rep(i, n) {
		cin >> c[i];
		-- c[i];
	}
	vector<vector<int>> g(n);
	UnionFind uf(2 * n);
	rep(i, m) {
		int u, v; cin >> u >> v;
		-- u, -- v;
		g[u].push_back(v), g[v].push_back(u);
		if(c[u] == c[v]) {
			uf.merge(u, v + n), uf.merge(u + n, v);
		}
	}
	uf.snapshot();
	vector<bool> check(k, true);
	ll cnt = k;
	rep(i, n) {
		if(!check[c[i]]) continue;
		if(uf.issame(i, i + n)) {
			check[c[i]] = 0;
			-- cnt;
		}
	}
	ll ans = cnt * (cnt - 1) / 2;
	map<P, vector<P>> mp;
	rep(v, n) {
		for(int u: g[v]) {
			if(!check[c[u]] or !check[c[v]] or c[u] == c[v]) {
				continue;
			}
			if(c[u] < c[v]) {
				mp[{c[u], c[v]}].push_back({u, v});
			}
		}
	}
	for(auto it: mp) {
		bool ok = true;
		for(auto p: it.sc) {
			int u = p.fr, v = p.sc;
			uf.merge(u, v + n);
			uf.merge(u + n, v);
			if(uf.issame(u, u + n) or uf.issame(v, v + n)) ok = 0;
		}
		if(!ok) -- ans;
		uf.rollback();
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}