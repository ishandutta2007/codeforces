/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

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

const int MAX = 30001;
const int VAL = 250;
int n, d;
int dp[MAX][2 * VAL + 5];

void solve() {
	cin >> n >> d;
    vector<int> cnt(MAX, 0);
    rep(i, n) {
        int p; cin >> p;
        cnt[p] ++;
    }
    rep(i, MAX) {
        rep(j, 2 * VAL + 5) {
            dp[i][j] = -inf;
        }
    }
    int offset = max(0, d - VAL);
    dp[d][d - offset] = cnt[d];
    int ans = 0;
    for(int i = d; i < MAX; ++ i) {
        rep(j, 2 * VAL + 2) {
            chmax(ans, dp[i][j]);
            if(i + offset + j - 1 < MAX and j - 1 > 0) chmax(dp[i + offset + j - 1][j - 1], dp[i][j] + cnt[i + offset + j - 1]);
            if(i + offset + j < MAX) chmax(dp[i + offset + j][j], dp[i][j] + cnt[i + offset + j]);
            if(i + offset + j + 1 < MAX and j + 1 < 2 * VAL + 2) chmax(dp[i + offset + j + 1][j + 1], dp[i][j] + cnt[i + offset + j + 1]);
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}