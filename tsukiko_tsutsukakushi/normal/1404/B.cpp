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
using namespace std;

#define int long long
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

int n, a, b, da, db; 
vector<vector<int>> g;

void dfs(int v, int p, vector<int>& dist, int di) {
    dist[v] = di;
    for(int nv: g[v]) {
        if(nv == p) continue;
        dfs(nv, v, dist, di + 1);
    }
}

void solve() {
	cin >> n >> a >> b >> da >> db;
    -- a, -- b;
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        -- u, -- v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(da >= db) {
        cout << "Alice" << endl;
        return;
    }
    vector<int> dist(n, inf);
    dist[a] = 0;
    dfs(a, -1, dist, 0);
    if(dist[b] <= da) {
        cout << "Alice" << endl;
        return;
    }
    int res = -1, st = -1;
    rep(i, n) {
        if(chmax(res, dist[i])) {
            st = i;
        }
    }
    dist.assign(n, inf);
    dist[st] = 0;
    dfs(st, -1, dist, 0);
    res = -1;
    rep(i, n) {
        chmax(res, dist[i]);
    }
    cout << (db >= 2 * da + 1 and res >= 2 * da + 1 ? "Bob" : "Alice") << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}