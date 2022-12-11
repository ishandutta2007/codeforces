#include <bits/stdc++.h>
#define int long long

using namespace std;

long long M;
const int N = 407;
int cnk[N][N];
int len_w[N];
int dp[N][N];

void init() {
    memset(cnk, 0, sizeof(cnk));
    cnk[0][0] = 1;
    for (int n = 1; n < N; n++) {
        cnk[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            cnk[n][k] = (cnk[n - 1][k - 1] + cnk[n - 1][k]) % M;
        }
    }

    for (int len = 1; len < N; len++) {
        len_w[len] = 0;
        for (int start = 0; start < len; start++) {
            len_w[len] = (len_w[len] + cnk[len - 1][start]) % M;
        }
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> M;
    init();

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i] = len_w[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] %= M;
            if (dp[i][j] == 0)
                continue;

            int l = i + 2;
            for (int r = l; r <= n; r++) {
                int len = r - l + 1;
                int cnt = (((dp[i][j] * len_w[len]) % M) * cnk[len + j][len]) % M;
                dp[r][j + len] += cnt;
            }
        }
    }
    int sm = 0;
    for (int j = 1; j <= n; j++)
        sm += dp[n][j];
    cout << (sm % M) << "\n";
    return 0;
}