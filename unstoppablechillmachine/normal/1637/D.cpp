#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S secondond
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 110;
const int SM = 10010;
int dp[N][SM], pref[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &x : a) {
            cin >> x;
        }
        for (auto &x : b) {
            cin >> x;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i * 100; j++) {
                dp[i][j] = 1e18;
            }
        }
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i - 1] + b[i - 1];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int was_sum = 0; was_sum <= (i - 1) * 100; was_sum++) {
                if (dp[i - 1][was_sum] < 1e18) {
                    dp[i][was_sum + a[i - 1]] = min(dp[i][was_sum + a[i - 1]], dp[i - 1][was_sum] + 2ll * a[i - 1] * was_sum + 2ll * b[i - 1] * (pref[i - 1] - was_sum));
                    dp[i][was_sum + b[i - 1]] = min(dp[i][was_sum + b[i - 1]], dp[i - 1][was_sum] + 2ll * b[i - 1] * was_sum + 2ll * a[i - 1] * (pref[i - 1] - was_sum));
                }
            }
        }
        int kek = 1e18;
        for (int sum = 0; sum <= n * 100; sum++) {
            kek = min(kek, dp[n][sum]);
        }
        for (int i = 0; i < n; i++) {
            kek += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
        }
        cout << kek << '\n';
    }
}