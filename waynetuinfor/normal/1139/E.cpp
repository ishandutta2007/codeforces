#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int p[maxn], c[maxn];
int match[maxn], ans[maxn];
vector<int> g[maxn];
bool v[maxn], adj[maxn][maxn];

bool dfs(int x) {
    v[x] = true;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (match[u] == -1 || !v[match[u]] && dfs(match[u])) {
            match[u] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]), --c[i];
    int d; scanf("%d", &d);
    vector<int> del;
    for (int i = 0; i < d; ++i) {
        int k; scanf("%d", &k);
        --k;
        del.push_back(k);
        assert(!v[k]);
        v[k] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!v[i])
            del.push_back(i);
    }
    assert((int)del.size() == n);
    int mex = 0;
    memset(match, -1, sizeof(match));
    memset(ans, 0, sizeof(ans));
    for (int i = n - 1; i >= 0; --i) {
        int j = del[i];
        g[p[j]].push_back(c[j]);
        while (true) {
            memset(v, false, sizeof(v));
            if (!dfs(mex)) break;
            ++mex;
        }
        ans[i] = mex;
    }
    for (int i = 1; i <= d; ++i) printf("%d\n", ans[i]);
    return 0;
}