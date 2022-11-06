#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int inf = 1e9;
vector<int> g[maxn];
int dp[maxn], dp2[maxn];

void dfs(int x, int p) {
    dp[x] = -2;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == p) continue;
        dfs(u, x);
        if (dp[u] == -1) dp[x] = -1;
        else if (dp[x] == -2) dp[x] = dp[u] + 1;
        else if (dp[x] != dp[u] + 1) dp[x] = -1;
    }    
    if (dp[x] == -2) dp[x] = 0;
}

void dfs2(int x, int p, int z) {
    dp2[x] = dp[x];
    if (z == -1) dp2[x] = -1;
    else if (dp2[x] != -1 && z != -2 && z + 1 != dp2[x]) dp2[x] = -1;
    multiset<int> s;
    set<int> t;
    if (z != -2) {
        s.insert(z);
        t.insert(z);
    }
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == p) continue;
        s.insert(dp[u]);
        t.insert(dp[u]);
    }
    if ((int)t.size() == 2 && t.count(-1) == 0) {
        int v = *t.begin() + *t.rbegin() + 2;
        while (v % 2 == 0) v >>= 1;
        if (dp2[x] == -1) dp2[x] = v;
        else if (v < dp2[x]) dp2[x] = v;
    }
    while (dp2[x] != -1 && dp2[x] % 2 == 0) dp2[x] >>= 1;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == p) continue;
        s.erase(s.find(dp[u]));
        int f = -2;
        if (s.count(-1)) f = -1;
        else if ((int)s.size() == 0) f = -2;
        else if (*s.rbegin() > *s.begin()) f = -1;
        else f = *s.begin();
        s.insert(dp[u]);
        if (f == -2) f = 0;
        else if (f != -1) f++;
        dfs2(u, x, f);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    dfs2(0, -1, -2);
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        if (dp2[i] != -1)
            ans = min(ans, dp2[i]);
    }
    if (ans == inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}