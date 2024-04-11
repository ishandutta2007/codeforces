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
    vector<vector<int>> dist(n, vector<int>(n, inf));
    rep(i, n) dist[i][i] = 0;
    rep(i, m) {
        int u, v, b; cin >> u >> v >> b;
        -- u, -- v;
        if(b == 1) {
            g[u].push_back(v);
            g[v].push_back(u);
            dist[u][v] = 1, dist[v][u] = -1;
        } else {
            g[u].push_back(v);
            g[v].push_back(u);
            dist[u][v] = 1, dist[v][u] = 1;
        }
    }
    vector<int> num(n, -1);
    bool ok = 1;
    auto rec = [&](auto &&self, int v, int val) -> void {
        num[v] = val;
        for(int nv: g[v]) {
            if(num[nv] == val) ok = 0;
            if(num[nv] == -1) self(self, nv, 1 - val); 
        }
    };
    rec(rec, 0, 0);
    if(!ok) {
        cout << "NO\n";
        return;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    rep(i, n) {
        if(dist[i][i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    int k = -1, ans = -inf;
    rep(i, n) {
        int res = -inf;
        rep(j, n) {
            chmax(res, dist[i][j]);
        }
        if(chmax(ans, res)) {
            k = i;
        }
    }
    cout << "YES\n";
    cout << ans << "\n";
    rep(i, n) {
        cout << dist[k][i] << " \n"[i == n - 1];
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