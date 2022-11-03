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

typedef pair<ll, tuple<int, int, int>> P2;

ll dist[200200][2][2];

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<P>> g(n, vector<P>());
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w; -- u, -- v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    rep(i, n) {
        rep(j, 2) {
            rep(k, 2) {
                dist[i][j][k] = INF;
            }
        }
    }
    priority_queue<P2, vector<P2>, greater<P2>> pque;
    pque.push({0, {0, 0, 0}});
    dist[0][0][0] = 0;
    while(pque.size()) {
        P2 p = pque.top(); pque.pop();
        ll di = p.fr;
        int v = get<0>(p.sc), f1 = get<1>(p.sc), f2 = get<2>(p.sc);
        if(di > dist[v][f1][f2]) continue;
        for(auto e: g[v]) {
            int nv = e.fr;
            ll co = e.sc;
            if(chmin(dist[nv][f1][f2], dist[v][f1][f2] + co)) {
                pque.push({dist[nv][f1][f2], {nv, f1, f2}});
            }
            if(!f1 and chmin(dist[nv][1][f2], dist[v][f1][f2])) {
                pque.push({dist[nv][1][f2], {nv, 1, f2}});
            }
            if(!f2 and chmin(dist[nv][f1][1], dist[v][f1][f2] + 2 * co)) {
                pque.push({dist[nv][f1][1], {nv, f1, 1}});
            }
            if(!f1 and !f2 and chmin(dist[nv][1][1], dist[v][f1][f2] + co)) {
                pque.push({dist[nv][1][1], {nv, 1, 1}});
            }
        }
    }
    for(int i = 1; i < n; ++ i) {
        cout << dist[i][1][1] << " \n"[i == n - 1];
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