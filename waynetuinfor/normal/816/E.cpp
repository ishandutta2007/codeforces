#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10, inf = 1e9 + 10;
vector<int> T[maxn];
int c[maxn], d[maxn], sz[maxn], dp[2][maxn][maxn];

void dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, b; cin >> n >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
        if (i == 1) continue;
        int p; cin >> p;
        T[p].push_back(i);
    }
    for (int i = 0; i < 2; ++i) for (int j = 0; j < maxn; ++j) {
        for (int k = 0; k < maxn; ++k) dp[i][j][k] = inf;
    }
    dfs(1, 0);
    for (int i = n; i >= 0; --i) {
        if (min(dp[0][1][i], dp[1][1][i]) <= b) return cout << i << endl, 0;
    }
    return 0;
}

void dfs(int x, int fa) {
    sz[x] = 1;
    dp[0][x][0] = 0;
    dp[0][x][1] = c[x];
    dp[1][x][1] = c[x] - d[x];
    for (int u : T[x]) if (u != fa) {
        dfs(u, x);
        for (int i = sz[x]; i >= 0; --i) {
            for (int j = sz[u]; j >= 0; --j) {
                dp[0][x][i + j] = min(dp[0][x][i + j], dp[0][x][i] + dp[0][u][j]);
                dp[1][x][i + j] = min(dp[1][x][i + j], dp[1][x][i] + min(dp[0][u][j], dp[1][u][j]));
            }
        }
        sz[x] += sz[u];
    }
}