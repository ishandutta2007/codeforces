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
vector<int> a, b, c;
vector<int> cost;
vector<vector<int>> g;

vector<int> dp0, dp1;
int ans;

void dfs(int v, int p, int mi) {
    if(b[v] == 1 && c[v] == 0) dp1[v] ++;
    if(b[v] == 0 && c[v] == 1) dp0[v] ++;
    chmin(cost[v], mi);
    //cerr << v << " " << dp0[v] << " " << dp1[v] << endl;

    for(int nv: g[v]) {
        if(nv == p) continue;
        dfs(nv, v, cost[v]);
        dp1[v] += dp1[nv];
        dp0[v] += dp0[nv];
    }
    //cerr << v << " " << dp0[v] << " " << dp1[v] << endl;
    if(dp1[v] >= dp0[v] && dp0[v] > 0) {
        ans += cost[v] * 2LL * dp0[v];
        dp1[v] -= dp0[v], dp0[v] = 0;
        //cerr << v << endl;
    } else if(dp1[v] < dp0[v] && dp1[v] > 0) {
        ans += cost[v] * 2LL * dp1[v];
        dp0[v] -= dp1[v], dp1[v] = 0;
        //cerr << v << endl;
    }
}

void solve() {
	cin >> n;
    a.resize(n); b.resize(n), c.resize(n);
    g.assign(n, vector<int>());
    cost.resize(n);
    int b0 = 0, b1 = 0, c0 = 0, c1 = 0;
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        cost[i] = a[i];
        if(b[i] == 0) ++ b0;
        else ++ b1;

        if(c[i] == 0) ++ c0;
        else ++ c1;
    }
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        -- u, -- v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(b0 != c0) {
        cout << -1 << endl;
        return;
    }
    dp0.assign(n, 0);
    dp1.assign(n, 0);
    ans = 0;
    dfs(0, -1, a[0]);
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