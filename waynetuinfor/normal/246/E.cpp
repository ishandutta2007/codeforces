#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, p = 131, mod = 1e9 + 87;
vector<int> graf[maxn];
int tin[maxn], tout[maxn], rev[maxn], hs[maxn], dep[maxn], ans[maxn], t;
bool vr[maxn];
unordered_map<int, int> c[maxn];

void dfs(int now, int fa, int d) {
    tin[now] = ++t;
    dep[now] = d;
    for (int u : graf[now]) if (u != fa) dfs(u, now, d + 1);
    tout[now] = t;
}

struct query { int l, r, pos, k, idx; };

void add(int p, int z) {
    c[dep[rev[p]]][hs[rev[p]]] += z;
    if (c[dep[rev[p]]][hs[rev[p]]] == 0) c[dep[rev[p]]].erase(hs[rev[p]]);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        char s[30]; int r; scanf("%s %d", s, &r);
        for (int j = 0; j < strlen(s); ++j) hs[i] = (hs[i] * 1ll * p % mod + s[j]) % mod;
        if (r) graf[i].push_back(r), graf[r].push_back(i), vr[i] = true;
    }
    for (int i = 1; i <= n; ++i) if (!vr[i]) dfs(i, 0, 0);
    for (int i = 1; i <= n; ++i) rev[tin[i]] = i;
    // for (int i = 1; i <= n; ++i) printf("dep[%d] = %d\n", i, dep[i]);
    // for (int i = 1; i <= n; ++i) printf("hs[%d] = %d\n", i, hs[i]);
    // for (int i = 1; i <= n; ++i) printf("tin[%d] = %d\n", i, tin[i]);
    // for (int i = 1; i <= n; ++i) printf("tout[%d] = %d\n", i, tout[i]);
    int m; scanf("%d", &m);
    int sz = 1 + (int)sqrt(n);
    vector<query> qr;
    for (int i = 0; i < m; ++i) {
        int v, k; scanf("%d %d", &v, &k);
        qr.push_back({ tin[v], tout[v], tin[v] / sz, k + dep[v], i });
    }
    sort(qr.begin(), qr.end(), [](const query &i, const query &j) { return tie(i.pos, i.r) < tie(j.pos, j.r); });
    for (int i = 0, l = 1, r = 0; i < qr.size(); ++i) {
        while (r < qr[i].r) add(++r, 1); while (r > qr[i].r) add(r--, -1);
        while (l > qr[i].l) add(--l, 1); while (l < qr[i].l) add(l++, -1);
        ans[qr[i].idx] = c[qr[i].k].size();
    }
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    return 0;
}