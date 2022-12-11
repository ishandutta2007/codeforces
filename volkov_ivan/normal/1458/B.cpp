#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 102;
int dp[N][N * N];

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    cout.precision(20);
    int n;
    cin >> n;
    int a[n + 1], c[n + 1];
    int C = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        C += c[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < N * N; j++)
            dp[i][j] = - N * N * N;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int cnt = i - 1; cnt >= 0; cnt--) {
            for (int sm = 0; sm < N * i; sm++) {
                if (dp[cnt][sm] < 0)
                    continue;
                dp[cnt + 1][sm + a[i]] = max(dp[cnt + 1][sm + a[i]], dp[cnt][sm] + c[i]);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        int best = 0;
        for (int sm = 0; sm < N * N; sm++) {
            if (dp[k][sm] >= 0) {
                best = max(best, min(2 * sm, C + dp[k][sm]));
            }
        }
        cout << fixed << 0.5l * best << ' ';
    }
}