#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7;
int a[maxn], p[maxn], tpow[maxn], c;
vector<pair<int, int>> graf[maxn];
bool v[maxn], stk[maxn], z;

int dfs(int now, int fa, int e) {
    // printf("dfs(%d, %d)\n", now, fa);
    int sz = 1;
    stk[now] = true; v[now] = true;
    p[now] = fa;
    for (auto u : graf[now]) if (u.second != e) {
        if (!v[u.first]) sz += dfs(u.first, now, u.second);
        else if (stk[u.first] && !z) {
            int k = now;
            z = true;
            while (true) {
                ++c;
                if (k == u.first) break;
                k = p[k];
            }
        }
    }
    stk[now] = false;
    return sz;
}

int main() {
    int n; scanf("%d", &n);
    tpow[0] = 1;
    for (int i = 1; i <= n; ++i) tpow[i] = tpow[i - 1] * 1ll * 2 % mod;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) graf[i].emplace_back(a[i], i), graf[a[i]].emplace_back(i, i);
    int ans = 1;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        c = 0; z = false;
        int sz = dfs(i, 0, 0);
        // printf("sz = %d\n", sz);
        int f = tpow[sz];
        // printf("c = %d\n", c);
        if (c > 0) f = (f - 2 * 1ll * tpow[sz - c] % mod + mod) % mod;
        ans = ans * 1ll * f % mod;
    }
    printf("%d\n", ans);
}