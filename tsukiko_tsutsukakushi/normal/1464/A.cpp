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
	int n, m; cin >> n >> m;
    vector<int> x(m), y(m);
    int ans = m;
    vector<bool> ok(m, 0);
    vector<int> gx(n, -1), gy(n, -1);
    rep(i, m) {
        cin >> x[i] >> y[i];
        -- x[i], -- y[i];
        if(x[i] == y[i]) {
            ok[i] = 1;
            -- ans;
        } else {
            gx[x[i]] = i, gy[y[i]] = i;
        }
    }
    UnionFind uf(m);
    rep(i, m) {
        if(!ok[i]) {
            if(gy[x[i]] != -1 and i < gy[x[i]]) {
                if(uf.issame(i, gy[x[i]])) ++ ans;
                uf.merge(i, gy[x[i]]);
            }
            if(gx[y[i]] != -1 and i < gx[y[i]]) {
                if(uf.issame(i, gx[y[i]])) ++ ans;
                uf.merge(i, gx[y[i]]);
            }
        }
    }
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