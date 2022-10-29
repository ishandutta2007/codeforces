#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = (1 << 30) - 1;
const int N = 505;
mt19937 rng(time(0));

int n, m, p;
LL a[N], dp[N][N];
char op[N];

int main() {
    cin >> n;
    rep(i, 1, n) {
        cin >> op[i];
        if (op[i] == '+')
            cin >> a[i];
    }

    LL ans = 0;
    rep(k, 1, n) if (op[k] == '+') {
        int up = 0;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        rep(i, 1, n) {
            if (i == k) {
                rep(j, 0, up) dp[i][j] = dp[i - 1][j];
            } else if (op[i] == '-') {
                rep(j, 0, up) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1] + (j == 0 && i < k ? dp[i - 1][0] : 0)) % P;
            } else { // op[i] == '+'
                up += (a[i] < a[k] || a[i] == a[k] && i < k);
                rep(j, 0, up) if (a[i] < a[k] || a[i] == a[k] && i < k) {
                    dp[i][j] = (dp[i - 1][j] + (j ? dp[i - 1][j - 1] : 0)) % P;
                }
                else {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j]) % P;
                }
            }
        }
        LL cnt = 0;
        rep(j, 0, up) cnt = (cnt + dp[n][j]) % P;
        ans = (ans + cnt * a[k]) % P;
        //cerr << k << " " << a[k] << " " << cnt << endl;
    }
    cout << ans << endl;
    return 0;
}