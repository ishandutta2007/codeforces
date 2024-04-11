#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int kN = 150'000 + 5;
const int kS = 500;
const int kMod = 998244353;
int ans[kN], fa[kN], sz[kN], tin[kN], tout[kN], rv[kN], op[kN], hd[kN][kN / kS], sk[kN][kN / kS];
vector<int> g[kN];
bool v[kN];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1LL * res * a % kMod;
        a = 1LL * a * a % kMod;
        n >>= 1;
    }
    return res;
}

void Dfs(int x, int p) {
    static int tk = 0;
    fa[x] = p;
    tin[x] = tk++;
    sz[x] = 1;
    for (int u : g[x]) {
        if (u == p) continue;
        Dfs(u, x);
        sz[x] += sz[u];
    }
    tout[x] = tk;
}

int fw[kN];

void Modify(int p, int v) {
    for (int i = p + 1; i < kN; i += i & -i) {
        fw[i] += v;
        if (fw[i] >= kMod) fw[i] -= kMod;
    }
}

int Query(int p) {
    int res = 0;
    for (int i = p + 1; i > 0; i -= i & -i) {
        res += fw[i];
        if (res >= kMod) res -= kMod;
    }
    return res;
}

void Bfs(int r, int n) {
    queue<int> q;
    for (int i = 0; i < n; ++i) v[i] = false;
    for (int i : g[r]) {
        hd[i][rv[r]] = i;
        sk[i][rv[r]] = 1;
        q.push(i);
        v[i] = true;
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int u : g[x]) {
            if (!v[u] && u != r) {
                v[u] = true;
                hd[u][rv[r]] = hd[x][rv[r]];
                sk[hd[x][rv[r]]][rv[r]] += 1;
                q.push(u);
            }
        }
    }
}

int main() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Dfs(0, -1);
    vector<int> hv;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() >= kS) {
            rv[i] = hv.size();
            hv.push_back(i);
            Bfs(i, n);
        }
    }
    const int kInv = fpow(n, kMod - 2);
    int all = 0;
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int v, d; scanf("%d%d", &v, &d); --v;
            if (g[v].size() < kS) {
                Modify(tin[v], kMod - 1LL * sz[v] * kInv % kMod * d % kMod);
                Modify(tout[v], 1LL * sz[v] * kInv % kMod * d % kMod);
                for (int u : g[v]) {
                    if (u == fa[v]) continue;
                    Modify(tin[u], 1LL * (n - sz[u]) * kInv % kMod * d % kMod);
                    Modify(tout[u], kMod - 1LL * (n - sz[u]) * kInv % kMod * d % kMod);
                }
                Modify(tin[v], d);
                Modify(tin[v] + 1, kMod - d);
                all += 1LL * sz[v] * kInv % kMod * d % kMod;
                all %= kMod;
            } else {
                op[v] += d;
                op[v] %= kMod;
            }
        } else {
            int v; scanf("%d", &v); --v;
            int ans = (Query(tin[v]) + all) % kMod;
            for (int i = 0; i < hv.size(); ++i) {
                int u = hv[i];
                if (u == v) {
                    ans += op[v];
                    ans %= kMod;
                } else {
                    ans += 1LL * (n - sk[hd[v][i]][i]) * kInv % kMod * op[u] % kMod;
                    ans %= kMod;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}