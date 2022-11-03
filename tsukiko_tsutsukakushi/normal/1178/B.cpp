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
    string s; cin >> s;
    int n = (int)s.size();
    static ll dp[1000100][3];
    rep(i, 1000100) rep(j, 3) dp[i][j] = 0;
    rep(i, n) {
        rep(j, 3) dp[i + 1][j] += dp[i][j];
        if(i + 1 < n and s[i] == 'v' and s[i + 1] == 'v') {
            dp[i + 2][0] += 1LL;
            dp[i + 2][2] += dp[i][1];
        }
        if(s[i] == 'o') {
            dp[i + 1][1] += dp[i][0];
        }
    }
    cout << dp[n][2] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}