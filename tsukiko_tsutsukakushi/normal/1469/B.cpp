/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n; cin >> n;
    vector<int> r(n);
    rep(i, n) {
        cin >> r[i];
    }
    int m; cin >> m;
    vector<int> b(m);
    rep(i, m) {
        cin >> b[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
    dp[0][0] = 0;
    int ans = -inf;
    rep(i, n + 1) {
        rep(j, m + 1) {
            chmax(ans, dp[i][j]);
            if(i < n) chmax(dp[i + 1][j], dp[i][j] + r[i]);
            if(j < m) chmax(dp[i][j + 1], dp[i][j] + b[j]);
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}