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
vector<int> w;
vector<vector<P>> g;

vector<vector<int>> dp;

int dfs(int v, int p) {
    int sz = (int)g[v].size();
    dp[v].assign(sz, -INF);
    int tmp = w[v];
    rep(i, sz) {
        if(g[v][i].fr == p) continue;
        dp[v][i] = dfs(g[v][i].fr, v) + g[v][i].sc + w[v];
        chmax(tmp, dp[v][i]);
    }
    return tmp;
}

void solve() {
	cin >> n;
    w.resize(n), g.assign(n, vector<P>());
    int ma = 0;
    rep(i, n) {
        cin >> w[i];
        chmax(ma, w[i]);
    }
    rep(i, n - 1) {
        int u, v, c; cin >> u >> v >> c;
        -- u, -- v;
        g[u].pb({v, -c});
        g[v].pb({u, -c});
    }
    dp.assign(n, vector<int>());
    dfs(0, -1);
    int ans = ma;
    rep(i, n) {
        sort(all(dp[i]));
        reverse(all(dp[i]));
        if(dp[i].size() > 0) {
            chmax(ans, dp[i][0]);
        }
        if(dp[i].size() > 1) {
            chmax(ans, dp[i][0] + dp[i][1] - w[i]);
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