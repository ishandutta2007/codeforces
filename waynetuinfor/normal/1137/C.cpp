#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxd = 50 + 5;
vector<int> g[maxn], r[maxn];
vector<int> member[maxn], pass;
char s[maxn][maxd];
int scc[maxn], dep[maxn], cycle[maxn];
int dp[maxn][maxd];
bool v[maxn];

void tarjan(int x) {
    v[x] = true;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (!v[u])
            tarjan(u);
    }
    pass.push_back(x);
}

void mark(int x, int y) {
    scc[x] = y;
    for (int i = 0; i < (int)r[x].size(); ++i) {
        int u = r[x][i];
        if (scc[u] == -1)
            mark(u, y);
    }
}

int dfs(int x, int d, int w) {
    int res = d;
    dep[x] = w;
    v[x] = true;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (scc[u] != scc[x]) continue;
        if (!v[u])         
            res = __gcd(res, dfs(u, d, w + 1));
        else if (dep[x] > dep[u])
            res = __gcd(res, (dep[x] - dep[u] + 1) % d);
    }
    return res;
}

int main() {
    int n, m, d; scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        r[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);

    for (int i = 0; i < n; ++i) {
        if (!v[i])
            tarjan(i);
    }
    memset(scc, -1, sizeof(scc));
    int p = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (scc[pass[i]] == -1)
            mark(pass[i], p++);
    }

    for (int i = 0; i < n; ++i) 
        member[scc[i]].push_back(i);

    memset(v, false, sizeof(v));
    for (int i = 0; i < p; ++i)
        cycle[i] = dfs(member[i][0], d, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j)
            dp[i][j] = -1;
    }
    dp[scc[0]][(d - dep[0] % d) % d] = 0;

    for (int c = 0; c < p; ++c) {
        for (int t = 0; t < d; ++t) {
            if (dp[c][t] < 0) continue;
            for (int i = 0; i < (int)member[c].size(); ++i) {
                int x = member[c][i];
                bool op = false;
                for (int j = (dep[x] + t) % d, k = 0; k < d / cycle[c]; ++k, (j += cycle[c]) %= d)
                    op |= s[x][j] == '1';

                dp[c][t] += op;
            }

            for (int i = 0; i < (int)member[c].size(); ++i) {
                int x = member[c][i];
                for (int z = 0; z < (int)g[x].size(); ++z) {
                    int u = g[x][z];
                    if (scc[u] == scc[x]) continue;
                    for (int j = (dep[x] + t) % d, k = 0; k < d / cycle[c]; ++k, (j += cycle[c]) %= d)
                        dp[scc[u]][(j + 1 + d - dep[u] % d) % d] = max(dp[scc[u]][(j + 1 + d - dep[u] % d) % d], dp[c][t]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, *max_element(dp[i], dp[i] + d));

    printf("%d\n", ans);
}