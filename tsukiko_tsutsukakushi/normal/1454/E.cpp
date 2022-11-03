/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind {
    vector<int> par, w;
    
    UnionFind(int n) : par(n, -1), w(n, 0) { }
    void init(int n) { par.assign(n, -1); w.assign(n, 0); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) {
            ++w[x];
            return false;
        }
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        w[x] += w[y];
        ++w[x];
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
 
    int wei(int x) {
        return w[root(x)];
    }
};

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);
    rep(i, n) {
        int u, v; cin >> u >> v; -- u, -- v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u] ++, deg[v] ++;
    }
    queue<int> que;
    vector<bool> used(n, 0);
    rep(i, n) {
        if(deg[i] <= 1) {
            que.push(i);
            used[i] = 1;
        }
    }
    while(que.size()) {
        int v = que.front(); que.pop();
        for(int nv: g[v]) {
            if(!used[nv]) {
                -- deg[nv];
                if(deg[nv] <= 1) {
                    que.push(nv);
                    used[nv] = 1;
                }
            }
        }
    }
    int cnt = 0;
    rep(i, n) {
        if(!used[i]) ++ cnt;
    }
    ll ans = 1LL * n * (n - 1) + 1LL * cnt * (cnt - 1);
    UnionFind uf(n);
    rep(v, n) {
        for(int nv: g[v]) {
            if(used[v] or used[nv]) uf.merge(v, nv);
        }
    }
    ll sum1 = 0, sum2 = 0;
    set<int> se;
    rep(i, n) {
        int r = uf.root(i);
        if(se.find(r) != se.end()) continue;
        se.insert(r);
        sum1 += uf.size(r);
        sum2 += uf.size(r) * uf.size(r);
    }
    ans += sum1 * sum1 - sum2 - (int)se.size() * ((int)se.size() - 1);
    ans /= 2;
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}