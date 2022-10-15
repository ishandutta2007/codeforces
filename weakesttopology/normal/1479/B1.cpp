#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
constexpr int inf = 0x3f3f3f3f, K = 5;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        exit(0);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    n = (int)size(a);
    vector<array<int, K>> dp(n);
    vector<int> pref(n);
    pref[0] = 1;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        fill(begin(dp[i]), end(dp[i]), -inf);
        pref[i] = pref[i - 1] + (a[i] != a[i - 1]);
        int suff = 1;
        // a[j] goes to the other list
        for (int j = i - 1; j >= max(0, i - K); --j) {
            // a[k] goes to the same list as a[i]
            for (int k = j - 1; k >= max(0, j - K); --k) {
                chmax(dp[i][i - j - 1], dp[j][j - k - 1] + suff - (a[k] == a[j + 1]));
            }
            chmax(dp[i][i - j - 1], suff + pref[j]);
            suff += a[j] != a[j + 1];
        }
        for (int k = 0; k < K; ++k) {
            chmax(ans, dp[i][k]);
        }
    }
    cout << ans << '\n';
    exit(0);
}