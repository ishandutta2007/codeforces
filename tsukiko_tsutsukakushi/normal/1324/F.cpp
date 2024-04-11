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

int n;
vector<vector<int>> g;
vector<int> a;

vector<int> dp;

void dfs1(int v, int p) {
    int res = (a[v] == 1 ? 1 : -1);
    for(auto nv: g[v]) {
        if(nv == p) continue;
        dfs1(nv, v);
        if(dp[nv] > 0) res += dp[nv];
    }
    dp[v] = res;
}

void dfs2(int v, int p) {
    if(p != -1) {
        int res = dp[p] - (dp[v] > 0 ? dp[v] : 0);
        dp[v] += max(res, 0);
    }
    for(auto nv: g[v]) {
        if(nv == p) continue;
        dfs2(nv, v);
    }
}

void solve() {
	cin >> n;
    a.resize(n);
    g.assign(n, vector<int>());
    dp.assign(n, 0);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(0, -1);
    rep(i, n) {
        cerr << dp[i] << " ";
    }
    cerr << endl;
    dfs2(0, -1);
    rep(i, n) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}