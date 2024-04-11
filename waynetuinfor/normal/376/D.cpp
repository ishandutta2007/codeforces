#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5000 + 10;
string s[maxn];
int dp[maxn][maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1][j - 1] == '1') dp[i][j] = dp[i][j - 1] + 1;
            else dp[i][j] = 0;
        }
    }
    /* for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << dp[i][j] << ' ';
        cout << endl;
    } */
    int ans = 0;
    for (int r = 1; r <= m; ++r) {
        // vector<int> vec;
        vector<int> cnt(maxn);
        for (int i = 1; i <= n; ++i) ++cnt[dp[i][r]];
        // sort(vec.begin(), vec.end(), [&](const int &a, const int &b) { return dp[a][r] > dp[b][r]; });
        int now = 0, l = m + 1, c = 0, ptr = m;
        while (ptr >= 0) {
            while (ptr >= 0 && cnt[ptr] == 0) --ptr;
            if (ptr < 0) break;
            // cout << "ptr = " << ptr << endl;
            ++c;
            now = max(now, c * ptr);
            --cnt[ptr];
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}