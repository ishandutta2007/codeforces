#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
long long sum[maxn], dp[maxn];
vector<int> g[maxn];

void dfs(int x, int p) {
    sum[x] = a[x];
    for (const int &u : g[x]) {
        if (u == p) continue;
        dfs(u, x);
        sum[x] += sum[u];
        dp[x] += dp[u] + sum[u];
    }
}

long long dfs2(int x, int p, long long fsum, long long fdp) {
    long long res = dp[x] + fdp + fsum;
    for (const int &u : g[x]) {
        if (u == p) continue;
        long long usum = sum[x] + fsum - sum[u];
        long long udp = dp[x] + fdp + fsum - dp[u] - sum[u];
        res = max(res, dfs2(u, x, usum, udp));
    }
    return res;
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
    printf("%lld\n", dfs2(0, -1, 0, 0));
}