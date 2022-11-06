#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
const long long inf = 1e18;
vector<pair<int, int>> g[maxn];
vector<int> qry[maxn];
int n, q, tin[maxn], tout[maxn], rev[maxn];
int l[maxn], r[maxn];
long long d[maxn], ans[maxn];
bool leaf[maxn];

void dfs(int x, int p) {
    static int tk = 0;
    tin[x] = tk++;
    int child = 0;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first, w = g[x][i].second;
        if (u == p) continue;
        d[u] = d[x] + w;
        ++child;
        dfs(u, x);
    }    
    tout[x] = tk;
    if (child == 0)
        leaf[x] = true;
}

long long st[maxn * 4], tg[maxn * 4];

void build(int l, int r, int o = 0) {
    if (r - l == 1) {
        if (leaf[rev[l]]) st[o] = d[rev[l]];
        else st[o] = inf;
        return;
    }
    build(l, (l + r) >> 1, o * 2 + 1);
    build((l + r) >> 1, r, o * 2 + 2);
    st[o] = min(st[o * 2 + 1], st[o * 2 + 2]);
}

void push(int o) {
    st[o * 2 + 1] += tg[o];
    st[o * 2 + 2] += tg[o];
    tg[o * 2 + 1] += tg[o];
    tg[o * 2 + 2] += tg[o];
    tg[o] = 0;
}

void modify(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        st[o] += v;
        tg[o] += v;
        return;
    }
    push(o);
    modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    st[o] = min(st[o * 2 + 1], st[o * 2 + 2]);
}

long long query(int l, int r, int ql, int qr, int o = 0) {
    if (l >= qr || ql >= r) return inf;
    if (l >= ql && r <= qr) return st[o];
    push(o);
    return min(query(l, (l + r) >> 1, ql, qr, o * 2 + 1),
               query((l + r) >> 1, r, ql, qr, o * 2 + 2));
}

void dfs2(int x, int p) {
    for (int i = 0; i < (int)qry[x].size(); ++i) 
        ans[qry[x][i]] = query(0, n, l[qry[x][i]], r[qry[x][i]]) + d[x];
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i].first, w = g[x][i].second;
        if (u == p) continue;
        modify(0, n, tin[u], tout[u], -2 * w);
        dfs2(u, x);
        modify(0, n, tin[u], tout[u], +2 * w);
    } 
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int p, w; scanf("%d%d", &p, &w); --p;
        g[p].emplace_back(i, w);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) 
        rev[tin[i]] = i;
    build(0, n); 
    for (int i = 0; i < q; ++i) {
        int u; scanf("%d%d%d", &u, &l[i], &r[i]);
        --u, --l[i];
        qry[u].push_back(i);
    }
    dfs2(0, -1);
    for (int i = 0; i < q; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}