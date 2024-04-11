#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
const int MOD = 998244353;

int n, dp[MAXN][2][2], nxt[2][2];
vector<int> tree[MAXN];

void add(int &a, long long b) {
    a = (a + b) % MOD;
}

void dfs(int u, int par) {
    dp[u][0][0] = 1;
    dp[u][1][0] = 1;

    for(int v: tree[u]) { 
        if (v == par)
            continue;       
        dfs(v, u);

        // c = chosen
        // a = has at least 1 incident edge
        for(int cu = 0; cu < 2; ++cu) {
            for(int au = 0; au < 2; ++au) {
                for(int cv = 0; cv < 2; ++cv) {
                    for(int av = 0; av < 2; ++av) {
                        // not choosing edge u-v
                        if ((av || !cv))
                            add(nxt[cu][au], 1LL * dp[u][cu][au] * dp[v][cv][av]);
                        
                        // choosing edge u-v
                        if (!cu || !cv)
                            add(nxt[cu][1], 1LL  * dp[u][cu][au] * dp[v][cv][av]);
                    }
                }
            }
        }

        for(int cu = 0; cu < 2; ++cu) { 
            for(int au = 0; au < 2; ++au) {
                dp[u][cu][au] = nxt[cu][au];
                nxt[cu][au] = 0;
            }
        }
    }

    // for(int cu = 0; cu < 2; ++cu)
    //     for(int au = 0; au < 2; ++au)
    //         printf("%d %d %d: %d\n", u, cu, au, dp[u][cu][au]);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int root = 2;
    dfs(root, -1);

    int ans = 0;
    for(int cu = 0; cu < 2; ++cu)
        for(int au = 0; au < 2; ++au)
            if (au || !cu)
                add(ans, dp[root][cu][au]);
    ans = (ans - 1 + MOD) % MOD;

    printf("%d\n", ans);

    return 0;
}