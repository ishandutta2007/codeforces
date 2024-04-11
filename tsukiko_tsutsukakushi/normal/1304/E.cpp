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

struct LCA {
    vector<vector<int>> parent; //parnt[d][v] := 2^d-th parnt of v
    vector<int> depth;
    LCA() {}
    LCA(const vector<vector<int>> &G, int r = 0) { init(G, r); }
    void init(const vector<vector<int>> &G, int r = 0) {
        int V = (int)G.size();
        int h = 1;
        while((1<<h) < V) ++h;
        parent.assign(h, vector<int> (V, -1));
        depth.assign(V, -1);
        dfs(G, r, -1, 0);
        for(int i = 0; i + 1 < (int)parent.size(); ++i) {
            for(int v = 0; v < V; ++v) {
                if(parent[i][v] != -1) {
                    parent[i + 1][v] = parent[i][parent[i][v]];
                }
            }
        }
    }
    void dfs(const vector<vector<int>> &G, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for(auto e: G[v]) if(e != p) dfs(G, e, v, d + 1); // estruct edge
    }
    int get(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        for(int i = 0; i < (int)parent.size(); ++i) {
            if((depth[v] - depth[u]) & (1<<i))
                v = parent[i][v];
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
    int dist(int u, int v) {
        int lca =  get(u, v);
        return abs(depth[u] - depth[lca]) + abs(depth[v] - depth[lca]);
    }
};

int n;
vector<vector<int>> g;

void solve() {
	cin >> n;
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    LCA lca(g, 0);
    int q; cin >> q;
    rep(i, q) {
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
        --x; --y; --a; --b;
        int di = lca.dist(a, b);
        int di1 = lca.dist(a, x) + 1 + lca.dist(y, b);
        int di2 = lca.dist(a, y) + 1 + lca.dist(x, b);
        if(k >= di && di % 2 == k % 2) {
            cout << "YES" << endl;
            continue;
        }
        if(k >=di1 || k >= di2) {
            if(k % 2 == di1 % 2) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}