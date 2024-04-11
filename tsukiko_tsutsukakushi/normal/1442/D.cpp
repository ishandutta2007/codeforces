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

const ll INF = 1LL<<60;

void solve() {
	int n, k; cin >> n >> k;
    vector<vector<ll>> a(n), s(n);
    vector<int> t(n);
    rep(i, n) {
        cin >> t[i];
        a[i].resize(t[i]);
        s[i].assign(t[i] + 1, 0);
        rep(j, t[i]) {
            cin >> a[i][j];
            s[i][j + 1] = s[i][j] + a[i][j];
        }
    }
    ll res = -INF;
    auto rec = [&](auto self, int left, int right, vector<ll> &dp) -> void {
        if(right - left == 1) {
            for(int i = 0; i <= k; ++ i) {
                if(k - i < (int)s[left].size()) chmax(res, dp[i] + s[left][k - i]);
            }
            return;
        }
        if(right - left <= 0) {
            return;
        }
        int mid = (left + right) / 2;
        // left
        {
            auto dp2 = dp;
            for(int i = mid; i < right; ++ i) {
                for(int j = k; j >= t[i]; -- j) {
                    chmax(dp2[j], dp2[j - t[i]] + s[i].back());
                }
            }
            self(self, left, mid, dp2);
        }
        // right 
        {
            auto dp2 = dp;
            for(int i = left; i < mid; ++ i) {
                for(int j = k; j >= t[i]; -- j) {
                    chmax(dp2[j], dp2[j - t[i]] + s[i].back());
                }
            }
            self(self, mid, right, dp2);
        }
    };
    vector<ll> dp(k + 1, -INF);
    dp[0] = 0;
    rec(rec, 0, n, dp);
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}