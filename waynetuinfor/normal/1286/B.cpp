#include <bits/stdc++.h>
using namespace std;

const int kN = 2000 + 5;
int c[kN], a[kN], sz[kN];
vector<int> g[kN];

bool Dfs(int x, vector<int> v) {
    if (sz[x] < c[x] + 1) return false;
    a[x] = v[c[x]];
    v.erase(v.begin() + c[x]);
    auto it = v.begin();
    for (int u : g[x]) {
        if (!Dfs(u, vector<int>(it, it + sz[u]))) return false;
        it += sz[u];
    }
    assert(it == v.end());
    return true;
}

void DfsSz(int x) {
    sz[x] = 1;
    for (int u : g[x]) {
        DfsSz(u);
        sz[x] += sz[u];
    }
}

int main() {
    int n; scanf("%d", &n);
    int root = -1;
    for (int i = 0; i < n; ++i) {
        int p; scanf("%d%d", &p, &c[i]); --p;
        if (p == -1) root = i;
        else g[p].push_back(i);
    }
    DfsSz(root);
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    bool ans = Dfs(root, v);
    if (!ans) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < n; ++i) printf("%d ", a[i] + 1);
        puts("");
    }
    return 0;
}