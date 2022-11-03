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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    rep(i, m) {
        int u, v; cin >> u >> v; -- u, -- v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> check(n, -1);
    vector<bool> used(n, 0);
    auto dfs = [&](auto &&self, int v, int p, int val) -> void {
        used[v] = 1;
        if(val == check[0]) {
            bool ok = 1;
            for(int nv: g[v]) {
                if(check[nv] == val) ok = 0;
            }
            if(!ok) {
                val = 1 - val;
            }
        }
        check[v] = val;
        for(int nv: g[v]) {
            if(nv == p) continue;
            if(!used[nv]) self(self, nv, v, 1 - val);
        }
        return;
    };
    dfs(dfs, 0, -1, 0);
    rep(i, n) {
        if(!used[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    vector<int> vec;
    rep(i, n) {
        if(check[i] == 0) vec.push_back(i);
    }
    cout << (int)vec.size() << "\n";
    for(int v: vec) {
        cout << v + 1 << " ";
    }
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}