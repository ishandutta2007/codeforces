#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, lg = 20;
vector<int> graf[maxn], tr[maxn];
int s[maxn], dfn[maxn], low[maxn], bcc[maxn], t;
int dep[maxn], p[lg][maxn], x[maxn], y[maxn], bcnt;
bool v[maxn];
stack<int> st;

void tarjan(int now, int fa) {
    dfn[now] = low[now] = ++t;
    st.push(now);
    for (int u : graf[now]) if (u != fa) {
        int to = s[u] - now;
        if (dfn[to]) {
            low[now] = min(low[now], dfn[to]);
            continue;
        }
        tarjan(to, u);
        low[now] = min(low[now], low[to]);
    }
    if (low[now] == dfn[now]) {
        ++bcnt;
        while (st.size()) {
            int k = st.top(); st.pop();
            bcc[k] = bcnt;
            if (k == now) break;
        }
    }
}

void dfs(int now, int fa, int d) {
    dep[now] = d; p[0][now] = fa;
    v[now] = true;
    for (int i = 1; (1 << i) <= d; ++i) p[i][now] = p[i - 1][p[i - 1][now]];
    for (int u : tr[now]) if (!v[u]) {
        dfs(u, now, d + 1);
    }
}

void dfs2(int now, int fa) {
    v[now] = true;
    for (int u : tr[now]) if (!v[u]) {
        dfs2(u, now);
        x[now] += x[u];
        y[now] += y[u];
    }
}

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    void merge(int a, int b) { p[find(a)] = find(b); }
} djs;

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < lg; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) b = p[i][b];
    }
    if (a == b) return a;
    for (int i = lg - 1; i >= 0; --i) {
        if (p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
        if (a == b) return a;
    }
    return p[0][a];
}

int main() {
    int n, m, q; scanf("%d %d %d", &n, &m, &q);
    djs.init();
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        djs.merge(a, b);
        s[i] = a + b;
        graf[a].push_back(i); graf[b].push_back(i);
    }
    for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, -1);
    for (int i = 1; i <= n; ++i) for (int j : graf[i]) {
        int to = s[j] - i;
        if (bcc[to] != bcc[i]) tr[bcc[i]].push_back(bcc[to]), tr[bcc[to]].push_back(bcc[i]);
    }
    for (int i = 1; i <= bcnt; ++i) if (!v[i]) dfs(i, 0, 0);
    bool ans = true;
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        if (djs.find(a) != djs.find(b)) {
            ans = false;
            continue;
        }
        a = bcc[a]; b = bcc[b];
        int c = lca(a, b);
        ++x[a]; --x[c]; ++y[b]; --y[c];
    }    
    memset(v, false, sizeof(v));
    for (int i = 1; i <= bcnt; ++i) if (!v[i]) dfs2(i, 0);
    for (int i = 1; i <= bcnt; ++i) if (x[i] > 0 && y[i] > 0) ans = false;
    if (ans) puts("Yes");
    else puts("No");
    return 0;
}