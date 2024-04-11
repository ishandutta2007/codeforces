#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxm = 10000 + 10, inf = 1e9 + 1;
int dp[maxn][maxm], a[maxn][maxn], sz[maxn], f[maxn][maxn];

void build(int id) {
    for (int i = 1; i <= sz[id]; ++i) a[id][i] += a[id][i - 1];
    int tot = a[id][sz[id]];
    for (int i = 0; i <= sz[id]; ++i) {
        for (int l = 1; l <= sz[id]; ++l) {
            if (l + i - 1 > sz[id]) break;
            int sum = a[id][l + i - 1] - a[id][l - 1];
            f[id][sz[id] - i] = max(f[id][sz[id] - i], tot - sum);
        }
    }
    f[id][0] = 0;
}

int g(int n, int m) {
    if (m == 0) return 0;
    if (n == 0) return -inf;
    if (dp[n][m]) return dp[n][m];
    for (int t = 0; t <= sz[n] && m - t >= 0; ++t) dp[n][m] = max(dp[n][m], g(n - 1, m - t) + f[n][t]);
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) cin >> a[i][j]; //  a[i][j] = j;
        sz[i] = k;
        build(i);
    }
    cout << g(n, m) << endl;
    return 0;
}