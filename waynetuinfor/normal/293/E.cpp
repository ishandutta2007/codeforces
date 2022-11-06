#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5, lg = 20;
vector<pair<int, int>> graf[maxn];
vector<tuple<int, int, int>> pt[maxn];
vector<int> ctree[maxn];
vector<int> vis;
int n, l, w, sz[maxn], ms[maxn], p[maxn];
int dis[lg][maxn][2], dep[maxn];
bool v[maxn];

void dfssz(int now) {
    sz[now] = 1;
    v[now] = true; ms[now] = 0;
    for (auto u : graf[now]) if (!v[u.first]) {
        dfssz(u.first);
        sz[now] += sz[u.first];
        ms[now] = max(ms[now], sz[u.first]);
    }
    vis.push_back(now);
} 

void dfsdis(int now, int d, vector<int> ds) {
    dis[d][now][0] = ds[0]; dis[d][now][1] = ds[1];
    v[now] = true;
    for (auto u : graf[now]) if (!v[u.first]) {
        dfsdis(u.first, d, { ds[0] + u.second, ds[1] + 1 });
    }
}

int dfscent(int now, int fa, int d) {
    dfssz(now);
    int c = -1;
    for (int u : vis) {
        if (max(ms[u], (int)vis.size() - sz[u]) <= (int)vis.size() / 2) c = u;
        v[u] = false;
    }
    dfsdis(c, d, { 0, 0 });
    for (int u : vis) v[u] = false;
    vis.clear();
    v[c] = true;
    p[c] = fa;
    dep[c] = d;
    for (auto u : graf[c]) if (!v[u.first]) ctree[c].push_back(dfscent(u.first, c, d + 1));
    return c;
}

struct fenwick {
    int dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] += v; }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v += dat[p]; return v; }
} bit;

long long solve(vector<tuple<int, int, int>> pt, int w, int l) {
    vector<pair<int, int>> qr;
    vector<int> ds;
    long long ans = 0;
    for (int i = 0; i < pt.size(); ++i) {
        if (get<0>(pt[i]) * 2 <= w && get<1>(pt[i]) * 2 <= l) --ans;
    }
    for (int i = 0; i < pt.size(); ++i) qr.emplace_back(w - get<0>(pt[i]), l - get<1>(pt[i])), ds.push_back(l - get<1>(pt[i]));
    for (int i = 0; i < pt.size(); ++i) ds.push_back(get<1>(pt[i]));
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i < pt.size(); ++i) get<1>(pt[i]) = lower_bound(ds.begin(), ds.end(), get<1>(pt[i])) - ds.begin() + 1;
    for (int i = 0; i < qr.size(); ++i) qr[i].second = lower_bound(ds.begin(), ds.end(), qr[i].second) - ds.begin() + 1;
    sort(pt.begin(), pt.end(), [](const tuple<int, int, int> &i, const tuple<int, int, int> &j) { return get<0>(i) < get<0>(j); });
    sort(qr.begin(), qr.end(), [](const pair<int, int> &i, const pair<int, int> &j) { return i.first < j.first; });
    int p = 0;
    for (int i = 0; i < qr.size(); ++i) {
        while (p < pt.size() && get<0>(pt[p]) <= qr[i].first) {
            bit.add(get<1>(pt[p]), 1);
            ++p;
        }
        ans += bit.qry(qr[i].second);
    }
    for (int i = 0; i < p; ++i) bit.add(get<1>(pt[i]), -1);
    return ans;
}

long long dfsans(int now, int d) {
    sort(pt[now].begin(), pt[now].end(), [](const tuple<int, int, int> &i, const tuple<int, int, int> &j) { return get<2>(i) < get<2>(j); });
    long long ans = solve(pt[now], w, l);
    sort(ctree[now].begin(), ctree[now].end());
    int p = 1;
    for (int u : ctree[now]) {
        vector<tuple<int, int, int>> to;
        while (p < pt[now].size() && get<2>(pt[now][p]) == u) to.push_back(pt[now][p]), ++p;
        ans -= solve(to, w, l);
    }
    for (int u : ctree[now]) ans += dfsans(u, d + 1);
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &l, &w);
    for (int i = 2; i <= n; ++i) {
        int p, w; scanf("%d %d", &p, &w);
        graf[p].emplace_back(i, w);
        graf[i].emplace_back(p, w);
    }
    int ct = dfscent(1, 0, 0);
    for (int i = 1; i <= n; ++i) { 
        for (int t = i, last = -1, j = dep[i], wt = 0, wl = 0; j >= 0; --j) {
            pt[t].emplace_back(wt, wl, last);
            if (j) wt = dis[j - 1][i][0], wl = dis[j - 1][i][1];
            last = t, t = p[t];
        }
    }
    printf("%" PRId64 "\n", (dfsans(ct, 0)) / 2);
    return 0;
}