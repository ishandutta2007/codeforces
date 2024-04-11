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

int n;
vector<vector<int>> g;
vector<int> res;

vector<int> sz, used, parent;

vector<int> cs;

void subdfs(int v, int p, int size) {
    sz[v] = 1, parent[v] = p;
    bool isCentroid = 1;
    for(int nv: g[v]) {
        if(nv == p) continue;
        if(used[nv]) continue;
        subdfs(nv, v, size);
        if(sz[nv] > size / 2) isCentroid = 0;
        sz[v] += sz[nv];
    }
    if(size - sz[v] > size / 2) isCentroid = 0;
    if(isCentroid) cs.push_back(v);
}

void dfs(int r, int size, int ite) {
    cs.clear();
    subdfs(r, -1, size);
    int center = cs[0];
    res[center] = ite;
    used[center] = 1;
    for(int nv: g[center]) {
        if(used[nv]) continue;
        if(nv == parent[center]) {
            dfs(nv, size - sz[center], ite + 1);
        } else {
            dfs(nv, sz[nv], ite + 1);
        }
    }
}

void solve() {
	cin >> n;
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        -- a, -- b;
        g[a].pb(b);
        g[b].pb(a);
    } 
    res.resize(n);
    sz.resize(n), used.assign(n, 0), parent.resize(n);
    dfs(0, n, 0);
    rep(i, n) {
        cout << (char)('A' + res[i]) << " \n"[i == n - 1];
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