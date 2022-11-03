/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
using namespace std;

// #define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, m, k;
vector<vector<P>> g;
vector<int> a, b;

void solve() {
	cin >> n >> m >> k;
    g.assign(n, vector<P>());
    a.resize(k), b.resize(k);
    rep(i, m) {
        int x, y, w; cin >> x >> y >> w;
        -- x, -- y;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    rep(i, k) {
        cin >> a[i] >> b[i];
        -- a[i], -- b[i];
    }
    vector<vector<int>> dist(n, vector<int>(n, inf));
    rep(s, n) {
        priority_queue<P, vector<P>, greater<P>> pque;
        dist[s][s] = 0;
        pque.push({0, s});
        while(pque.size()) {
            P p = pque.top(); pque.pop();
            int di = p.fr, v = p.sc;
            if(di > dist[s][v]) continue;
            for(auto e: g[v]) {
                int nv = e.fr, co = e.sc;
                if(chmin(dist[s][nv], di + co)) {
                    pque.push({di + co, nv});
                }
            }
        }
    }
    int ans = 0;
    rep(i, k) {
        ans += dist[a[i]][b[i]];
    }
    // cerr << ans << endl;
    rep(x, n) {
        for(auto e: g[x]) {
            int y = e.fr;
            int res = 0;
            rep(i, k) {
                res += min({dist[a[i]][b[i]], dist[a[i]][x] + dist[y][b[i]], dist[a[i]][y] + dist[x][b[i]]});
                // cerr << dist[a[i]][x] + dist[y][b[i]] << " " << dist[a[i]][y] + dist[x][b[i]] << endl;
            }
            chmin(ans, res);
            // cerr << x << " " << y << " " << res << endl;
        }
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