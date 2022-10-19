#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        vector<int> dp(n, 1);
        int answer = 1;
        for (int i = 0; i < n; i++) {
            answer = max(answer, dp[i]);
            for (int j = i + 1; j < min(i + 256, n); j++) {
                if ((a[i] ^ j) < (a[j] ^ i)) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}