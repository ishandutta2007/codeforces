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

vector<int> cs;
vector<int> sz;
int lf;

void dfs(int v, int p) {
    sz[v] = 1;
    bool ok = 1;
    for(int nv: g[v]) {
        if(nv == p) continue;
        dfs(nv, v);
        sz[v] += sz[nv];
        if(sz[nv] > n / 2) ok = 0;
    }
    if(n - sz[v] > n / 2) ok = 0;
    if(ok) {
        // cerr << v << endl;
        cs.push_back(v);
    }
}

void ddfs(int v, int p) {
    if(g[v].size() == 1 and g[v][0] == p) {
        lf = v;
    }
    for(int nv: g[v]) {
        if(nv == p) continue;
        ddfs(nv, v);
    }
}

void solve() {
	cin >> n;
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int x, y; cin >> x >> y; 
        -- x, -- y;
        g[x].pb(y);
        g[y].pb(x);
    }
    sz.resize(n);
    cs.clear();
    dfs(0, -1);
    if(cs.size() == 1) {
        cout << 1 << " " << g[0][0] + 1 << endl;
        cout << 1 << " " << g[0][0] + 1 << endl;
    } else {
        int a = cs[0], b = cs[1];
        ddfs(a, b);
        cout << lf + 1 << " " << g[lf][0] + 1 << endl;
        cout << lf + 1 << " " << b + 1 << endl;
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