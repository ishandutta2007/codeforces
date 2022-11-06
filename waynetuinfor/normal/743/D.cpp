#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const long long inf = 1e18 + 10;
int a[maxn];
long long dp[2][maxn], sum[maxn];
vector<int> G[maxn];

void dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b); G[b].push_back(a);
    }
    fill(dp[0], dp[0] + maxn, -inf); fill(dp[1], dp[1] + maxn, -inf);
    dfs(0, -1);
    if (dp[1][0] == -inf) cout << "Impossible" << endl;
    else cout << dp[1][0] << endl;
    return 0;
}

void dfs(int x, int fa) {
    vector<long long> ch;
    sum[x] = a[x];
    for (int u : G[x]) if (u != fa) {
        dfs(u, x);
        sum[x] += sum[u];
        dp[0][x] = max(dp[0][x], dp[0][u]);
        dp[1][x] = max(dp[1][x], dp[1][u]);
        ch.push_back(dp[0][u]);
    }
    sort(ch.begin(), ch.end());
    if (ch.size() > 1) dp[1][x] = max(dp[1][x], ch[ch.size() - 1] + ch[ch.size() - 2]);
    dp[0][x] = max(dp[0][x], sum[x]);
    // cout << "x = " << x << " sum[x] = " << sum[x] << " dp[0][x] = " << dp[0][x] << " dp[1][x] = " << dp[1][x] << endl;
}