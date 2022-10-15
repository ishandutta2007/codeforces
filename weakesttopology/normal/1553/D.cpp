#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int n = (int)size(s), m = (int)size(t);
        reverse(begin(s), end(s));
        reverse(begin(t), end(t));
        vector<int> dp(n + 2, -inf);
        dp[0] = 0;
        bool good = false;
        for (int i = 0; i < n; ++i) {
            if (dp[i] < 0) continue;
            if (dp[i] == m) {
                good = true;
                break;
            }
            if (s[i] == t[dp[i]]) dp[i + 1] = max(dp[i + 1], dp[i] + 1);
            dp[i + 2] = dp[i];
        }
        if (dp[n] == m) good = true;
        cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}