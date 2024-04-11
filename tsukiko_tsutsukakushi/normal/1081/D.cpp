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
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind {
    vector<int> par, w, cnt;
    
    UnionFind(int n, vector<int> cnt_) : par(n, -1), w(n, 0), cnt(cnt_) { }
    
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
        cnt[x] += cnt[y];
        ++w[x];
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
 
    int wei(int x) {
        return w[root(x)];
    }

    int count(int x) {
        return cnt[root(x)];
    }
};

typedef pair<int, pair<int, int>> P2;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> x(k);
    vector<bool> check(n, 0);
    vector<int> cnt(n, 0);
    rep(i, k) {
        cin >> x[i]; -- x[i];
        check[x[i]] = 1;
        cnt[x[i]] ++;
    }
    vector<P2> es(m);
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w;
        -- u, -- v;
        es[i] = {w, {u, v}};
    }
    sort(all(es));
    UnionFind uf(n, cnt);
    int ans;
    rep(i, m) {
        int u = es[i].sc.fr, v = es[i].sc.sc, c = es[i].fr;
        if(!uf.issame(u, v)) {
            // u = uf.root(u), v = uf.root(v);
            // if(check[u] and check[v]) ans = c;
            // if(check[u]) check[v] = 1;
            // if(check[v]) check[u] = 1;
            if(uf.count(u) > 0 and uf.count(v) > 0) ans = c;
            uf.merge(u, v);
        }
    }
    rep(i, k) {
        cout << ans << " \n"[i == k - 1];
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}