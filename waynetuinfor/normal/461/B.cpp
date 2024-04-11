#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int a[maxn], dp[2][maxn];
vector<int> G[maxn];

void dfs(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        G[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) cin >> a[i];
    dfs(0);
    cout << dp[1][0] << endl;
    return 0;
}

void dfs(int x) {
    dp[0][x] = 1, dp[1][x] = 0;
    for (int u : G[x]) {
        dfs(u);
        dp[1][x] = (long long)dp[1][x] * (long long)dp[0][u] % mod;
        dp[1][x] = ((long long)dp[1][x] + (long long)dp[0][x] * (long long)dp[1][u] % mod) % mod;
        dp[0][x] = (long long)dp[0][x] * (long long)dp[0][u] % mod;
    }
    if (a[x]) dp[1][x] = dp[0][x];
    else dp[0][x] = (dp[0][x] + dp[1][x]) % mod;
}