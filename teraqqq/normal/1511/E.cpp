#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int MOD = 998244353;
const int R2 = (MOD+1)/2;
const int R4 = (R2+MOD)/2;

void solve() {
    int n, m; cin >> n >> m;
    int mul = 1, ans = 0;

    const int k = n * m;
    vector<int> dp(k+1);

    for (int i = 2; i <= k; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
        if (dp[i] >= MOD) dp[i] -= MOD;

        if (dp[i] % 2 == 0) {
            dp[i] /= 2;
        } else {
            dp[i] = (dp[i] + MOD) / 2;
        }

        dp[i] += R4;
        if (dp[i] >= MOD) dp[i] -= MOD;
    }

    vector<string> s(n);
    for (auto& x : s) cin >> x;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ) {
            if (s[i][j] == 'o') {
                int t = j;
                while (j < m && s[i][j] == 'o') ++j;
                ans += dp[j - t];
                if (ans >= MOD) ans -= MOD;
            } else {
                ++j;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ) {
            if (s[i][j] == 'o') {
                int t = i;
                while (i < n && s[i][j] == 'o') ++i;
                ans += dp[i - t];
                if (ans >= MOD) ans -= MOD;
            } else {
                ++i;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'o') {
                ans += ans;
                if (ans >= MOD) ans -= MOD;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}