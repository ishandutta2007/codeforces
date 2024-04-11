/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

// #define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    static int dp[5050][5050];
    rep(i, 5050) {
        rep(j, 5050) {
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    rep(i, n) {
        rep(j, m) {
            if(a[i] == b[j]) {
                chmax(dp[i + 1][j + 1], dp[i][j] + 2);
                chmax(dp[i + 1][j + 1], 2);
            }
            chmax(dp[i + 1][j + 1], dp[i + 1][j] - 1);
            chmax(dp[i + 1][j + 1], dp[i][j + 1] - 1);
            chmax(ans, dp[i + 1][j + 1]);
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