#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const long long inf = 1e18;
int a[maxn];
vector<int> g[maxn];
long long dp[2][maxn];
int cnt[maxn];

void dfs(int x, int p) {
    dp[0][x] = -inf;
    dp[1][x] = a[x];
    for (const int &u : g[x]) {
        if (u == p) continue;
        dfs(u, x);
        dp[0][x] = max(dp[0][x], max(dp[0][u], dp[1][u]));
        if (dp[1][u] > 0) dp[1][x] += dp[1][u];
    }
}

long long dfs2(int x, int p) {
    long long s = a[x];
    for (const int &u : g[x]) {
        if (u == p) continue;
        long long y = dfs2(u, x);
        cnt[x] += cnt[u];
        if (y > 0) s += y;
    }
    if (s == max(dp[0][0], dp[1][0])) ++cnt[x], s = 0;
    return s;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1); 
    dfs2(0, -1);    
    printf("%lld %d\n", max(dp[0][0], dp[1][0]) * cnt[0], cnt[0]);
}