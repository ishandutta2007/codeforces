#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int dp[3][maxn], x, y;

void dfs(int now, int fa) {
    vector<int> vec;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        int bst = max(max(dp[0][u], dp[1][u]), dp[2][u]);
        dp[2][now] = max(dp[2][now] + bst, dp[1][now] + max(dp[0][u], dp[1][u]) + 1);
        dp[1][now] = max(dp[1][now] + bst, dp[0][now] + max(dp[0][u], dp[1][u]) + 1);
        dp[0][now] += bst;
    }
}

long long get(int ex, int ey) { return x * 1ll * ex + y * 1ll * ey; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n >> x >> y;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    if (x == y) return cout << get(0, n - 1) << endl, 0;
    if (x > y) {
        bool b = false;
        for (int i = 1; i <= n; ++i) b |= ((int)G[i].size() == n - 1);
        if (b) cout << get(1, n - 2) << endl;
        else cout << get(0, n - 1) << endl;
        return 0;
    }
    dfs(1, 0);
    int c = max(max(dp[0][1], dp[1][1]), dp[2][1]);
    cout << get(c, n - 1 - c) << endl; 
    return 0;
}