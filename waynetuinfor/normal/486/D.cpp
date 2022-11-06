#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, mod = 1e9 + 7;
vector<int> G[maxn];
int a[maxn], d, n, dp[maxn];
// dp1: max, dp2: min

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

void dfs(int now, int fa, int rt) {
    dp[now] = 1;
    for (int u : G[now]) if (u != fa) {
        if (a[u] < a[rt] || a[u] > a[rt] + d) continue;
        if (a[u] == a[rt] && u < rt) continue;
        dfs(u, now, rt);
        dp[now] = mul(dp[now], add(dp[u], 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> d >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v); G[v].emplace_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dfs(i, 0, i);
        ans = add(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}