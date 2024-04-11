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

int n;
vector<vector<int>> g;

vector<vector<int>> parent;
vector<int> depth;

void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for(auto e: g[v]) {
        if(e == p) continue;
        dfs(e, v, d + 1);
    }
}

int get(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    for(int i = 0; i < (int)parent.size(); ++i) {
        if((depth[v] - depth[u]) & (1<<i)) {
            v = parent[i][v];
        }
    }
    if(u == v) return u;
    for(int i = (int)parent.size() - 1; i >= 0; --i) {
        if(parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

// the parent of u to the direction of v
int getParent(int u, int v) {
    if(u == v) return -1;
    int lca = get(u, v);
    if(lca != u) return parent[0][u];
    int p = v;
    for(int i = (int)parent.size() - 1; i >= 0; --i) {
        if(parent[i][p] != -1 && depth[parent[i][p]] > depth[u]) {
            p = parent[i][p];
        }
    }
    return p;
}

int num[3030][3030];

int rec(int v, int p) {
    int res = 1;
    for(auto e: g[v]) {
        if(e == p) continue;
        num[v][e] = rec(e, v);
        res += num[v][e];
    }
    if(p != -1) {
        num[v][p] = n - res;
    }
    return res;
}

vector<vector<int>> dp;

int calcdp(int u, int v) {
    if(dp[u][v] != -1) return dp[u][v];
    if(dp[v][u] != -1) return dp[v][u];
    if(u == v) return 0;
    int res = 0;
    int up = getParent(u, v);
    int vp = getParent(v, u);
    chmax(res, calcdp(up, v));
    chmax(res, calcdp(u, vp));
    res += num[up][u] * num[vp][v];
    return dp[u][v] = dp[v][u] = res;
}

void solve() {
	cin >> n;
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    parent.assign(15, vector<int>(n, -1));
    depth.assign(n, -1);
    dfs(0, -1, 0);
    for(int i = 0; i + 1 < (int)parent.size(); ++i) {
        rep(v, n) {
            if(parent[i][v] != -1) {
                parent[i + 1][v] = parent[i][parent[i][v]];
            }
        }
    }
    rep(i, 3030) {
        rep(j, 3030) {
            num[i][j] = -1;
        }
    }
    int _ = rec(0, -1);
    dp.assign(n, vector<int>(n, -1));
    int ans = 0;
    rep(i, n) {
        for(int j = i + 1; j < n; ++j) {
            chmax(ans, calcdp(i, j));
        }
    }
    //cerr << num[0][1] << " " << num[1][0] << endl;
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