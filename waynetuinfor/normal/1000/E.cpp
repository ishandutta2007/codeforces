#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
vector<int> g[maxn], gr[maxn];
int tin[maxn], low[maxn], t;
int bcc[maxn], sz;
stack<int> st;
bool v[maxn];

void dfs(int x, int p) {
    tin[x] = low[x] = ++t;
    st.push(x);
    for (int u : g[x]) if (u != p) {
        if (tin[u]) {
            low[x] = min(low[x], tin[u]);
            continue;
        }
        dfs(u, x);
        low[x] = min(low[x], low[u]);
    }
    if (tin[x] == low[x]) {
        ++sz;
        while (st.size()) {
            int u = st.top(); st.pop();
            bcc[u] = sz;
            if (u == x) break;
        }
    }
}

int f, fd;

void dfs1(int x, int d) {
    if (d > fd) fd = d, f = x;
    v[x] = true;
    for (int u : gr[x]) if (!v[u]) dfs1(u, d + 1);
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x , &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j : g[i]) {
            if (bcc[j] == bcc[i]) continue;
            gr[bcc[i]].push_back(bcc[j]);
            gr[bcc[j]].push_back(bcc[i]);
        }
    }
    fd = -1;
    dfs1(1, 0);
    fd = -1;
    memset(v, false, sizeof(v));
    dfs1(f, 0);
    printf("%d\n", fd);
}