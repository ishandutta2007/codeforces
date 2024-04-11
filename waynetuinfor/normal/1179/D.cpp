#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
vector<int> g[maxn];
int n, sz[maxn], a[maxn];
long long dp[maxn][2], b[maxn];

void pre(int x, int p) {
    sz[x] = 1;
    auto it = find(g[x].begin(), g[x].end(), p);
    if (it != g[x].end()) g[x].erase(it);

    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        assert(u != p);

        pre(u, x);
        sz[x] += sz[u];
    }
}

long long eval(int x, int y) {
    return dp[x][0] + dp[y][0] + 
           (n - sz[x] - sz[y]) * 1ll * (n - sz[x] - sz[y]);
}

bool elim(int x, int y, int z, bool sgn) {
    if (sgn)
        return (b[x] - b[y]) * (a[z] - a[y]) <= (b[y] - b[z]) * (a[y] - a[x]);
    else
        return (b[x] - b[y]) * (a[z] - a[y]) >= (b[y] - b[z]) * (a[y] - a[x]);
}

void dfs(int x, int p) {
    dp[x][0] = sz[x] * 1ll * sz[x];
    dp[x][1] = 1e18;

    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        dfs(u, x);
        dp[x][0] = min(dp[x][0], dp[u][0] + (sz[x] - sz[u]) * 1ll * (sz[x] - sz[u]));
        dp[x][1] = min(dp[x][1], dp[u][1]);

        a[u] = 2 * sz[u];
        b[u] = n * 1ll * n - 2ll * n * sz[u] + sz[u] * 1ll * sz[u] + dp[u][0];
    }

    sort(g[x].begin(), g[x].end(), [&](int u, int v) {
        return a[u] == a[v] ? b[u] < b[v] : a[u] < a[v];
    });

    deque<int> dq;

    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        dp[x][1] = min(dp[x][1], dp[u][0] + (n - sz[u]) * 1ll * (n - sz[u]));

        while (dq.size() >= 2) {
            int p = dq[(int)dq.size() - 2];
            int q = dq[(int)dq.size() - 1];
            if (eval(p, u) <= eval(q, u)) dq.pop_back();
            else break;
        }

        if (!dq.empty())
            dp[x][1] = min(dp[x][1], eval(dq.back(), u));

        if (!dq.empty() && a[dq.back()] == a[u]) continue;

        while (dq.size() >= 2) {
            int p = dq[(int)dq.size() - 2];
            int q = dq[(int)dq.size() - 1];
            if (elim(p, q, u, false)) dq.pop_back();
            else break;
        }

        dq.push_back(u);
    }

    reverse(g[x].begin(), g[x].end());
    dq.clear();

    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        dp[x][1] = min(dp[x][1], dp[u][0] + (n - sz[u]) * 1ll * (n - sz[u]));

        while (dq.size() >= 2) {
            int p = dq[(int)dq.size() - 2];
            int q = dq[(int)dq.size() - 1];
            if (eval(p, u) <= eval(q, u)) dq.pop_back();
            else break;
        }

        if (!dq.empty())
            dp[x][1] = min(dp[x][1], eval(dq.back(), u));

        while (dq.size() >= 2) {
            int p = dq[(int)dq.size() - 2];
            int q = dq[(int)dq.size() - 1];
            if (a[u] == a[q]) dq.pop_back();
            else if (elim(p, q, u, true)) dq.pop_back();
            else break;
        }

        dq.push_back(u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    pre(0, -1);
    dfs(0, -1);

    printf("%lld\n", n * 1ll * (n - 1) / 2 + (n * 1ll * n - dp[0][1]) / 2);
}