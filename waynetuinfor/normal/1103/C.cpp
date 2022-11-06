#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int fa[maxn], dep[maxn], ch[maxn];
vector<int> g[maxn], leaf;
bool v[maxn];

void dfs(int x, int p) {
    v[x] = true;
    fa[x] = p;
    dep[x] = ~p ? dep[p] + 1 : 0;
    for (const int &u : g[x]) {
        if (v[u]) continue;
        ++ch[x];
        dfs(u, x);
    }
    if (ch[x] == 0) leaf.push_back(x);
}

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    int x = -1;
    for (int i = 0; i < (int)leaf.size(); ++i) {
        if (dep[leaf[i]] * k >= n) 
            x = leaf[i];
    }
    if (x != -1) {
        assert(x != -1);
        puts("PATH");
        vector<int> ans;
        while (true) {
            ans.push_back(x);
            if (x == 0) break;
            x = fa[x];
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); ++i)
            printf("%d ", ans[i] + 1);
        puts("");
    } else {
        assert((int)leaf.size() >= k);
        puts("CYCLES");
        for (int i = 0; i < k; ++i) {
            int u = leaf[i];
            vector<int> up;
            for (int j : g[u]) {
                if (j == fa[u]) continue;
                if (dep[j] < dep[u])
                    up.push_back(j);
            }
            sort(up.begin(), up.end(), [&](int i, int j) {
                return dep[i] > dep[j];     
            });
            assert((int)up.size() > 1);
            int x = up[0], y = up[1];
            if (dep[x] > dep[y]) swap(x, y);
            vector<int> ans;
            if ((dep[u] - dep[x] + 1) % 3) {
                while (true) {
                    ans.push_back(u);
                    if (u == x) break;
                    u = fa[u];
                } 
            } else if ((dep[u] - dep[y] + 1) % 3) {
                while (true) {
                    ans.push_back(u);
                    if (u == y) break;
                    u = fa[u];
                }
            } else if ((dep[y] - dep[x] + 2) % 3) {
                ans.push_back(u);
                while (true) {
                    ans.push_back(y);
                    if (y == x) break;
                    y = fa[y];
                }
            } else {
                throw;
            }
            printf("%d\n", (int)ans.size());
            for (int j = 0; j < (int)ans.size(); ++j)
                printf("%d ", ans[j] + 1);
            puts("");
        }
    }
}