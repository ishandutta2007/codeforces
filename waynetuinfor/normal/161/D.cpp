#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10, maxk = 500 + 10;
vector<int> G[maxn];
int dp[maxk][maxn], n, k;
long long ans;

void dfs(int now, int fa, int d) {
    dp[0][now] = 1;
    if (d >= k) ++ans;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
        for (int kk = 1; kk < maxk; ++kk) dp[kk][now] += dp[kk - 1][u];
    }
    for (int u : G[now]) if (u != fa) {
        for (int kk = 0; kk <= k; ++kk) {
            if (k - kk - 1 >= 0) {
                int tmp = (k - kk - 2 >= 0 ? dp[k - kk - 2][u] : 0);
                dp[k - kk - 1][now] -= tmp;
                ans += (long long)dp[kk][u] * (long long)dp[k - kk - 1][now];
                dp[k - kk - 1][now] += tmp;
            }
        }
    }
    // cout << "now = " << now << " ans = " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0, 0);
    cout << ans / 2 << endl;
    return 0;
}