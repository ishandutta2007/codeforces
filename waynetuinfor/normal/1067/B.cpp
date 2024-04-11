#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int deg[maxn], dp[maxn];
bool inq[maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    if (n <= 3) {
        puts("No");
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            dp[i] = 0;
            q.push(i);
            inq[i] = true;
        } else {
            if (deg[i] < 3) {
                puts("No");
                return 0;
            }
        }
    }
    while (q.size()) {
        int x = q.front(); q.pop();
        for (const int &u : g[x]) {
            if (inq[u]) continue;
            --deg[u];
            if (~dp[u] && dp[u] != dp[x] + 1) {
                puts("No");
                return 0;
            }
            dp[u] = dp[x] + 1;
            if (deg[u] == 1) q.push(u), inq[u] = true;
        }
    }
    int c = *max_element(dp, dp + n);
    int z = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == c) ++z;
    }
    if (z > 1) {
        puts("No");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) continue;
        if (dp[i] == c) continue;
        if (g[i].size() < 4) {
            puts("No");
            return 0;
        }
    }
    if (c == k) puts("Yes");
    else puts("No");
    return 0;
}