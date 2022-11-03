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

int n, k;
vector<int> a;
vector<vector<int>> g, dp, sdp;

void dfs(int v, int p) {
    for(int nv: g[v]) {
        if(nv == p) continue;
        dfs(nv, v);
    }
    for(int d = 200; d >= 0; -- d) {
        if(d == 0) {
            dp[v][d] = a[v];
            for(int nv: g[v]) {
                if(nv == p) continue;
                dp[v][d] += sdp[nv][k];
            }
            chmax(sdp[v][d], sdp[v][d + 1]);
            chmax(sdp[v][d], dp[v][d]);
        } else {
            for(int nv: g[v]) {
                if(nv == p) continue;
                int res = dp[nv][d - 1];
                for(int nnv: g[v]) {
                    if(nnv == nv || nnv == p) continue;
                    res += sdp[nnv][max(k - d, d - 1)];
                }
                chmax(dp[v][d], res);
            }
            chmax(sdp[v][d], sdp[v][d + 1]);
            chmax(sdp[v][d], dp[v][d]);
        }
        //if(d <= 10) cerr << v << " " << d << " " << dp[v][d] << " " << sdp[v][d] << endl;
    }
}

void solve() {
	cin >> n >> k;
    a.resize(n);
    rep(i, n) {
        cin >> a[i];
    }
    g.assign(n, vector<int>());
    rep(i, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp.assign(n, vector<int>(210, 0));
    sdp.assign(n, vector<int>(210, 0));
    dfs(0, -1);
    cout << sdp[0][0] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}