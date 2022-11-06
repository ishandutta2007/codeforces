#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353;
int pw[maxn], color[maxn], cnt, sz;
vector<int> g[maxn];

bool dfs(int x, int c = 0) {
    color[x] = c;
    if (c == 0) ++cnt;
    ++sz;
    bool res = true;
    for (const int &u : g[x]) {
        if (color[u] == -1) res &= dfs(u, c ^ 1);
        else res &= color[u] != color[x];
    }
    return res;
}

int main() {
    int t; scanf("%d", &t);
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) pw[i] = pw[i - 1] * 2 % mod;
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            --x, --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) color[i] = -1;
        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) continue;
            cnt = 0, sz = 0;
            if (!dfs(i)) ans = 0;
            int way = (pw[cnt] + pw[sz - cnt]) % mod;
            ans = ans * 1ll * way % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}