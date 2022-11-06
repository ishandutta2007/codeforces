#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn], r[maxn];
int n, m, x[maxn], y[maxn], c[maxn], scc[maxn], sz[maxn], tour[maxn], deg[maxn], p;
bool v[maxn];

void dfs(int x) {
    v[x] = true;
    for (const int &u : g[x]) {
        if (v[u]) continue;
        dfs(u);
    }
    tour[p++] = x;
}

void rdfs(int x) {
    scc[x] = p;
    ++sz[scc[x]];
    for (const int &u : r[x]) {
        if (~scc[u]) continue;
        rdfs(u);
    }
}

bool check(int t) {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        r[i].clear();
        v[i] = false;
        scc[i] = -1;
        sz[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        if (c[i] <= t) continue;
        g[x[i]].push_back(y[i]);
        r[y[i]].push_back(x[i]);
    }
    p = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i]) continue;
        dfs(i);
    }
    p = 0;
    for (int i = n - 1; i >= 0; --i) {
        int x = tour[i];
        if (scc[x] != -1) continue;
        rdfs(x);
        p++;
    }
    for (int i = 0; i < p; ++i) {
        if (sz[i] > 1) return false;
    }
    return true;
}

vector<int> get(int t) {
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < m; ++i) {
        if (c[i] <= t) continue;
        g[x[i]].push_back(y[i]);
        ++deg[y[i]];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) q.push(i);
    }
    p = 0;
    while (q.size()) {
        int x = q.front(); q.pop();
        scc[x] = p++;
        for (const int &u : g[x]) {
            if ((--deg[u]) == 0)
                q.push(u);
        }
    }
    vector<int> rev;
    for (int i = 0; i < m; ++i) {
        if (c[i] > t) continue;
        if (scc[x[i]] > scc[y[i]]) rev.push_back(i);
    }
    return rev;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &c[i]);
        --x[i], --y[i];
    }
    int ans = 1e9 + 1;
    for (int d = 30; d >= 0; --d) {
        if (ans - (1 << d) < 0) continue;
        if (check(ans - (1 << d))) ans -= (1 << d);
    }
    vector<int> v = get(ans);
    printf("%d %d\n", ans, (int)v.size());
    for (int i = 0; i < (int)v.size(); ++i) printf("%d ", v[i] + 1);
    puts("");
    return 0;
}