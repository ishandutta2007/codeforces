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
    int n, k; cin >> n >> k;
    vector<vector<P>> g(n, vector<P>());
    rep(i, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        -- u, -- v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    auto dfs = [&](auto&& self, int v, int p) -> pair<ll, ll> {
        vector<pair<ll, ll>> vec;
        for(auto e: g[v]) {
            if(e.fr == p) continue;
            int nv = e.fr;
            ll co = e.sc;
            auto res = self(self, nv, v);
            vec.push_back({res.fr, res.sc + co});
        }
        ll sum = 0;
        for(auto p: vec) {
            sum += p.fr;
        }
        sort(all(vec), [&](P a, P b){return (a.sc - a.fr) > (b.sc - b.fr);});
        pair<ll, ll> ret = {sum, sum};
        rep(i, min(k, (int)vec.size())) {
            if(i < k - 1 and vec[i].sc - vec[i].fr >= 0) {
                ret.sc += vec[i].sc - vec[i].fr;
            }
            if(vec[i].sc - vec[i].fr >= 0) {
                ret.fr += vec[i].sc - vec[i].fr;
            }
        }
        return ret;
    };
    auto ret = dfs(dfs, 0, -1);
    cout << ret.fr << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}