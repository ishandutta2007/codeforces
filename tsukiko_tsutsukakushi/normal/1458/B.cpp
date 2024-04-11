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
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    static ld dp[105][10010];
    rep(i, 105) rep(j, 10010) dp[i][j] = -inf;
    dp[0][0] = 0.0;
    rep(i, n) {
        for(int k = i; k >= 0; -- k) {
            for(int j = 0; j < 10010; ++ j) {
                //
                if(j + a[i] < 10010) chmax(dp[k + 1][j + a[i]], dp[k][j] + b[i]);
                //
                chmax(dp[k][j], dp[k][j] + (ld)b[i] / 2.0);
            }
        }
    }
    for(int k = 1; k <= n; ++ k) {
        ld ans = 0.0;
        for(int j = 0; j < 10010; ++ j) {
            chmax(ans, min(dp[k][j], (ld)j));
        }
        cout << ans << " \n"[k == n];
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}