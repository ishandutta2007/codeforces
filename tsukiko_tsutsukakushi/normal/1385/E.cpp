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
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
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

int n, m;

vector<vector<int>> g, h;

// vector<bool> seen, finished;

// bool ok;

// void dfs(int v, int p) {
//     seen[v] = 1;
//     for(int nv: g[v]) {
//         if(nv == p) continue;
//         if(finished[nv]) continue;
//         if(seen[nv] and !finished[nv]) {
//             ok = 0;
//             return;
//         }
//         dfs(nv, v);
//         if(!ok) return;
//     }
//     finished[v] = 1;
// }

void solve() {
	cin >> n >> m;
    g.assign(n, vector<int>());
    h.assign(n, vector<int>());
    vector<P> es;
    vector<int> deg(n, 0);
    rep(i, m) {
        int t, x, y; cin >> t >> x >> y;
        -- x, -- y;
        if(t == 0) {
            es.push_back({x, y});
        } else {
            g[x].pb(y);
            deg[y] ++;
            h[y].pb(x);
        }
    }
    queue<int> que;
    rep(i, n) {
        if(deg[i] == 0) que.push(i);
    }
    vector<int> ord;
    while(!que.empty()) {
        int v = que.front(); que.pop();
        ord.push_back(v);
        for(int nv: g[v]) {
            -- deg[nv];
            if(deg[nv] == 0) que.push(nv);
        }
    }
    if(ord.size() != n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> ids(n);
    int cur = 0;
    for(int v: ord) {
        ids[v] = cur;
        ++ cur;
    }
    rep(v, n) {
        for(int nv: g[v]) {
            cout << v + 1 << " " << nv + 1 << endl;
        }
    }
    for(P p: es) {
        int x = p.fr, y = p.sc;
        if(ids[x] < ids[y]) {
            cout << x + 1 << " " << y + 1 << endl;
        } else {
            cout << y + 1 << " " << x + 1 << endl;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}