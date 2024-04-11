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
LL ans[N];

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
            //cerr << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    ans[1] = 0;
    rep(m, 2, n) {
        ans[m] = 1ll * ans[m - 1] * m % P;
        rep(diff, 1, m - 1) {
            LL sum = 0, pair = 0;
            int k = (m - 1) * (m - 2) / 2;
            rep(i, 0, k) {
                pair = (pair + dp[m - 1][i] * sum) % P;
                if (i >= diff)
                    sum = (sum + dp[m - 1][i - diff]) % P;
            }
            ans[m] = (ans[m] + pair * (m - diff)) % P;
            //cerr << m << " " << diff << " " << pair << endl;
        }
    }
    cout << ans[n] << endl;
}