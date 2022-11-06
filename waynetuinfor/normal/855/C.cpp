#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int n, m, k, x, dp[15][3][maxn];
vector<int> G[maxn];

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return a * 1ll * b % mod; }

void dfs(int now, int fa) {
    dp[0][0][now] = m - k; dp[0][1][now] = k - 1; dp[1][2][now] = 1; 
    // if (G[now].size() == 1) return;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        vector<vector<int>> tmp(15, vector<int>(3));
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; i + j <= x; ++j) {
                tmp[i + j][0] = add(tmp[i + j][0], mul(dp[j][0][now], dp[i][0][u]));
                tmp[i + j][0] = add(tmp[i + j][0], mul(dp[j][0][now], dp[i][1][u]));
                tmp[i + j][1] = add(tmp[i + j][1], mul(dp[j][1][now], dp[i][0][u]));
                tmp[i + j][1] = add(tmp[i + j][1], mul(dp[j][1][now], dp[i][1][u]));
                tmp[i + j][1] = add(tmp[i + j][1], mul(dp[j][1][now], dp[i][2][u]));
                tmp[i + j][2] = add(tmp[i + j][2], mul(dp[j][2][now], dp[i][1][u]));
            }
        }
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j < 3; ++j) dp[i][j][now] = tmp[i][j];
            // for (int j = 0; j < 3; ++j) cout << "dp[" << i << "][" << j << "][" << now << "] = " << dp[i][j][now] << endl;
        }
    }
    // for (int i = 0; i <= x; ++i) {
        // for (int j = 0; j < 3; ++j) cout << "dp[" << i << "][" << j << "][" << now << "] = " << dp[i][j][now] << endl;
    // }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    cin >> k >> x;
    int ans = 0;
    dfs(1, 0);
    for (int i = 0; i <= x; ++i) {
        ans = add(ans, add(dp[i][0][1], add(dp[i][1][1], dp[i][2][1])));
    }
    cout << ans << endl;
    return 0;
}