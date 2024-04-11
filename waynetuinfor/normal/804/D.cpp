#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> graf[maxn], kz[maxn];
vector<long long> skz[maxn];
bool v[maxn];
int mdep[maxn], dp[maxn], tdp[maxn];

namespace djs {
    int p[maxn], sz[maxn];
    void init(int n) { for (int i = 0; i < n; ++i) p[i] = i, sz[i] = 1; }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { sz[x = find(x)] > sz[y = find(y)] ? p[y] = x, sz[x] += sz[y] : p[x] = y, sz[y] += sz[x]; }
}

void dfsdp(int now, int fa) {
    v[now] = true;
    mdep[now] = 0;
    for (int u : graf[now]) if (!v[u]) {
        dfsdp(u, now);
        mdep[now] = max(mdep[now], mdep[u] + 1);
    }
}

void dfs(int now, int fa, int p) {
    dp[now] = max(mdep[now], p);
    pair<int, int> z1 = make_pair(0, -1), z2 = make_pair(0, -1);
    for (int u : graf[now]) if (u != fa) {
        if (mdep[u] + 1 > z1.first) z2 = z1, z1 = make_pair(mdep[u] + 1, u);
        else if (mdep[u] + 1 > z2.first) z2 = make_pair(mdep[u] + 1, u);
    }
    for (int u : graf[now]) if (u != fa) {
        int k = (z1.second == u ? z2.first : z1.first);
        dfs(u, now, max(p + 1, k + 1));
    }
}

map<pair<int, int>, double> vans;

int main() {
    int n, m, qr; scanf("%d %d %d", &n, &m, &qr);
    djs::init(n);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        djs::merge(a, b);
        graf[a].push_back(b); graf[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) if (!v[i]) dfsdp(i, -1), dfs(i, -1, 0);
    for (int i = 0; i < n; ++i) kz[djs::find(i)].push_back(dp[i]);
    for (int i = 0; i < n; ++i) if (kz[i].size()) {
        sort(kz[i].begin(), kz[i].end());
        tdp[i] = kz[i].back();
        skz[i].push_back(kz[i][0]);
        for (int j = 1; j < kz[i].size(); ++j) skz[i].push_back(skz[i].back() + kz[i][j]);
    }
    while (qr--) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        if (djs::find(a) == djs::find(b)) {
            puts("-1");
            continue;
        }
        a = djs::find(a), b = djs::find(b);
        if (djs::sz[a] > djs::sz[b]) swap(a, b);
        if (vans.find(make_pair(a, b)) != vans.end()) {
            printf("%.20lf\n", vans[make_pair(a, b)]);
            continue;
        }
        long long q = djs::sz[a] * 1ll * djs::sz[b];
        int sta = max(tdp[a], tdp[b]);
        long long p = 0;
        for (int i = 0; i < kz[a].size(); ++i) {
            int c = upper_bound(kz[b].begin(), kz[b].end(), sta - kz[a][i] - 1) - kz[b].begin();
            p += sta * 1ll * c;
            int r = kz[b].size() - c;
            long long y = (c == 0 ? skz[b].back() : skz[b].back() - skz[b][c - 1]);
            p += kz[a][i] * 1ll * r + y + r;
        }
        vans[make_pair(a, b)] = 1.0 * p / q;
        printf("%.20lf\n", 1.0 * p / q);
    }
    return 0;
}