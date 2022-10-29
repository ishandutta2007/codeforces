#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
//const LL P = 998244353;
const int N = 505;

int T, n, P;
vector<LL> dp[N];
LL ans[N], sum[N*N/2];

int main() {
    cin >> n >> P;
    dp[1].resize(1), dp[1][0] = 1;
    rep(i, 2, n) {
        int k = i * (i - 1) / 2;
        dp[i].resize(k + 1);
        dp[i][0] = 1;
        rep(j, 1, k) {
            dp[i][j] = dp[i][j - 1];
            if (j <= k - i + 1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % P;
            if (j >= i)
                dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + P) % P;
        }
    }

    ans[1] = 0;
    rep(m, 2, n) {
        ans[m] = 1ll * ans[m - 1] * m % P;
        vector<LL> &a = dp[m - 1];

        LL pair = 0, sum2 = 0, sum3 = 0;
        int k = (m - 1) * (m - 2) / 2;
        sum[0] = 1;
        rep(i, 1, k) {
            pair = (pair + a[i] * sum3) % P;
            sum[i] = (sum[i - 1] + a[i]) % P;
            sum2 = (sum2 + (i >= 2 ? sum[i - 2] : 0) - (i >= m + 1 ? sum[i - m - 1] : 0) + P) % P;
            sum3 = (sum3 + sum[i - 1] * (m - 1) - sum2 + P) % P;
        }
        ans[m] = (ans[m] + pair) % P;
    }
    cout << ans[n] << endl;
}