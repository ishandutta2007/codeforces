#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1e5 + 10;
const int K = 450;
int dp[N][K], a[N], pref[N];

int get_sum(int l, int r) {
    return pref[r] - pref[l - 1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        dp[n][1] = a[n];
        for (int i = 2; i < K; i++) {
            dp[n][i] = 0;
        }
        for (int i = n - 1; i >= 1; i--) {
            dp[i][1] = max(a[i], dp[i + 1][1]);
            for (int j = 2; j < K; j++) {
                dp[i][j] = dp[i + 1][j];
                if (i + j - 1 < n && get_sum(i, i + j - 1) < dp[i + j][j - 1]) {
                    dp[i][j] = max(dp[i][j], get_sum(i, i + j - 1));
                }
            }
        }
        int ans = 1;
        while (dp[1][ans + 1] > 0) {
            ans++;
        }
        cout << ans << '\n';
    }
}