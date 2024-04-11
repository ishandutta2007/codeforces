/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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

const int inf = 1'000'000'007;

void solve() {
	int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m + 5, 0);
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    sort(all(a));
    static int dp[1000100][3][3];
    rep(i, 1000100) {
        rep(j, 3) {
            rep(k, 3) {
                dp[i][j][k] = -inf;
            }
        }
    }
    dp[0][0][0] = 0;
    rep(i, m) {
        rep(j, 3) {
            rep(k, 3) {
                // i + 1: cnt[i + 1] - j - k
                // i + 2: cnt[i + 2] - k
                if(cnt[i] - j - k >= 0) {
                    rep(l, 3) {
                        if(cnt[i + 1] - j - k - l >= 0 and cnt[i + 2] - k - l >= 0 and cnt[i + 3] - l >= 0) {
                            chmax(dp[i + 1][k][l], dp[i][j][k] + l + (cnt[i + 1] - j - k - l) / 3);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i, m + 1) {
        rep(j, 3) {
            rep(k, 3) {
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