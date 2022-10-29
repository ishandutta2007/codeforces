#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define PB push_back
typedef long long LL;
const int N = 3e5 + 5;

struct edge {
    int to;
    LL w;
};
int n, m, k, tmp, tim, top, cnt;
vector<int> g[N];
vector<edge> g2[N];
int Q[N], dfn[N], low[N], scc[N];
int x[N], y[N], v[N], v2[N];
LL dp[N], c[N], w[N], c2[N], ans[N];

void tarjan(int x, int fa) {
    dfn[x] = low[x] = ++tim;
    Q[++top] = x;
    for (auto u : g[x])
        if (u != fa) {
            if (!dfn[u]) {
                tarjan(u, x);
                low[x] = min(low[x], low[u]);
            } else
                low[x] = min(low[x], dfn[u]);
        }

    if (low[x] == dfn[x]) {
        cnt++;
        while (Q[top] != x)
            scc[Q[top--]] = cnt;
        scc[Q[top--]] = cnt;
    }
}

void dfs(int x, int fa) {
    dp[x] = c2[x];
    for (auto ele : g2[x]) {
        int u = ele.to;
        if (u != fa) {
            dfs(u, x);
            v2[x] += v2[u];
            if (v2[u] == 0 || v2[u] == k)
                dp[x] += dp[u];
            else
                dp[x] += max(dp[u] - ele.w, 0ll);
        }
    }
}

void dfs2(int x, int fa) {
    for (auto ele : g2[x]) {
        int u = ele.to;
        if (u != fa) {
            if (v2[u] == 0 || v2[u] == k)
                ans[u] = ans[x];
            else
                ans[u] = dp[u] + max(ans[x] - max(dp[u] - ele.w, 0ll) - ele.w, 0ll);
            dfs2(u, x);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 1, k) scanf("%d", &tmp), v[tmp] = 1;
    rep(i, 1, n) scanf("%d", c + i);
    rep(i, 1, m) scanf("%d", w + i);
    rep(i, 1, m) {
        scanf("%d%d", x + i, y + i);
        g[x[i]].PB(y[i]), g[y[i]].PB(x[i]);
    }

    tarjan(1, 0);
    rep(i, 1, n) {
        v2[scc[i]] += v[i];
        c2[scc[i]] += c[i];
    }
    rep(i, 1, m) {
        int x1 = scc[x[i]], y1 = scc[y[i]];
        if (x1 != y1)
        	g2[x1].PB({y1, w[i]}),
        	g2[y1].PB({x1, w[i]});
    }

    dfs(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);
    
    rep(i, 1, n) printf("%lld ", ans[scc[i]]);
    return 0;
}