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

void solve() {
	int n, r1, r2, r3, d; cin >> n >> r1 >> r2 >> r3 >> d;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    static ll dp[1001000][2];
    rep(i, 1001000) rep(j, 2) dp[i][j] = 1e18;
    dp[0][0] = 0;
    dp[1][0] = 1LL * r1 * a[0] + r3;
    dp[1][1] = min(1LL * r2, 1LL * r1 * a[0] + r1);
    for(int i = 1; i < n; ++ i) {
        // 0 -> 0
        chmin(dp[i + 1][0], dp[i][0] + d + 1LL * r1 * a[i] + r3);
        // 0 -> 1
        chmin(dp[i + 1][1], dp[i][0] + d + min(1LL * r2, 1LL * r1 * a[i] + r1));
        // 1 -> 0
        chmin(dp[i + 1][0], dp[i][1] + d + 1LL * r1 * a[i] + r3 + d + r1 + d);
        chmin(dp[i + 1][0], dp[i][1] + d + 1LL * r1 * a[i] + r1 + d + r1 + d + r1);
        chmin(dp[i + 1][0], dp[i][1] + d + r2 + d + r1 + d + r1);
        // 1 -> 1
        chmin(dp[i + 1][1], dp[i][1] + d + 1LL * r1 * a[i] + r3 + d + r1 + d);
        chmin(dp[i + 1][1], dp[i][1] + d + 1LL * r1 * a[i] + r1 + d + r1 + d);
        chmin(dp[i + 1][1], dp[i][1] + d + r2 + d + r1 + d);

        if(i == n - 1) {
            chmin(dp[i + 1][0], dp[i][1] + d + 1LL * r1 * a[i] + r3 + d + r1);
        }
    }
    cout << dp[n][0] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}