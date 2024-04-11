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

void solve() {
	int n, m, l; cin >> n >> m >> l;
    vector<int> r(n), g(m), b(l);
    rep(i, n) cin >> r[i];
    rep(i, m) cin >> g[i];
    rep(i, l) cin >> b[i];
    sort(all(r)), reverse(all(r));
    sort(all(g)), reverse(all(g));
    sort(all(b)), reverse(all(b));
    static int dp[220][220][220];
    rep(i, 220) rep(j, 220) rep(k, 220) dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    int ans = 0;
    rep(i, n + 1) {
        rep(j, m + 1) {
            rep(k, l + 1) {
                if(i >= 1 and j >= 1 and dp[i - 1][j - 1][k] >= 0) chmax(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
                if(k >= 1 and j >= 1 and dp[i][j - 1][k - 1] >= 0) chmax(dp[i][j][k], dp[i][j - 1][k - 1] + b[k - 1] * g[j - 1]);
                if(i >= 1 and k >= 1 and dp[i - 1][j][k - 1] >= 0) chmax(dp[i][j][k], dp[i - 1][j][k - 1] + r[i - 1] * b[k - 1]);
                chmax(ans, dp[i][j][k]);
            }
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