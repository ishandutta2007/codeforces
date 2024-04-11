#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int w[maxn], tin[maxn], low[maxn], t, cnt, bcc[maxn], dep[maxn], p[maxn], top[maxn], sz[maxn], maxson[maxn], cid[maxn], c;
vector<int> G[maxn], g[maxn], vb[maxn];
bool cut[maxn];
stack<int> s;
multiset<int> wi[maxn];

void dfs1(int now, int fa) {
    tin[now] = low[now] = ++t;
    s.push(now);
    int ch = 0;
    for (int u : G[now]) if (u != fa) {
        ++ch;
        if (tin[u]) low[now] = min(low[now], tin[u]);
        else {
            dfs1(u, now);
            low[now] = min(low[now], low[u]);
            if (low[u] >= tin[now]) {
                ++cnt; cut[now] = true;
                while (true) {
                    int v = s.top(); s.pop();
                    bcc[v] = cnt;
                    vb[cnt].push_back(v);
                    if (v == u) break;
                }
                bcc[now] = cnt; vb[cnt].push_back(now);
            }
        }
    }
    if (fa == 0 && ch == 1) cut[now] = false;
    if (cut[now]) cid[now] = ++c;
}

void dfs2(int now, int fa, int d) {
    dep[now] = d; p[now] = fa;
    maxson[now] = -1; sz[now] = 1;
    for (int u : g[now]) if (u != fa) {
        dfs2(u, now, d + 1);
        sz[now] += sz[u];
        if (maxson[now] == -1 || sz[u] > sz[maxson[now]]) maxson[now] = u;
    }
}

void link(int now, int tp) {
    tin[now] = ++t; top[now] = tp;
    if (maxson[now] == -1) return;
    link(maxson[now], tp);
    for (int u : g[now]) if (u != p[now]) {
        if (u == maxson[now]) continue;
        link(u, u);
    }
}

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int val;
    static SegmentTree mem[400000];
    static SegmentTree *ptr;
    SegmentTree() {} 
    SegmentTree(int L, int R) {
        lc = rc = nullptr; val = 0;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
    }
    void pull() {
        val = min(lc->val, rc->val);
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) {
            val = v;
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return inf;
        if (L >= l && R <= r) return val;
        return min(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st, SegmentTree::mem[400000], *SegmentTree::ptr = mem;

pair<int, int> lca(int a, int b) {
    int ta = top[a], tb = top[b];
    int ret = inf;
    while (ta != tb) {
        if (dep[ta] < dep[tb]) {
            swap(a, b);
            swap(ta, tb);
        }
        ret = min(ret, st->query(1, t, tin[ta], tin[a]));
        a = p[ta]; ta = top[a];
    }
    ret = min(ret, st->query(1, t, min(tin[a], tin[b]), max(tin[a], tin[b])));
    return make_pair(ret, (dep[a] > dep[b] ? b : a));
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q; 
    for (int i = 1; i <= n; ++i) cin >> w[i];
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs1(1, 0);
    for (int i = 1; i <= cnt; ++i) {
        for (int j : vb[i]) if (cid[j]) {
            g[cid[j]].push_back(i + c);
            g[i + c].push_back(cid[j]);
        }
    } 
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
    }
    memset(tin, 0, sizeof(tin)); t = 0;
    dfs2(1, 0, 0); link(1, 1);
    st = new (SegmentTree::ptr++) SegmentTree(1, t);
    for (int i = 1; i <= n; ++i) if (cid[i]) st->modify(1, t, tin[cid[i]], w[i]);
    for (int i = 1; i <= cnt; ++i) {
        for (int j : vb[i]) if (!cid[j] || p[i + c] != cid[j]) {
            wi[i].insert(w[j]);
        }
        st->modify(1, t, tin[i + c], *wi[i].begin());
    }
    while (q--) {
        char ch; int a, b; cin >> ch >> a >> b;
        if (ch == 'C') {
            if (cid[a]) {
                st->modify(1, t, tin[cid[a]], b);
                if (p[cid[a]] < c) {
                    w[a] = b;
                    continue;
                }
                wi[p[cid[a]] - c].erase(w[a]);
                wi[p[cid[a]] - c].insert(b);
                w[a] = b;
                st->modify(1, t, tin[p[cid[a]]], *wi[p[cid[a]] - c].begin());
            } else {
                wi[bcc[a]].erase(w[a]);
                wi[bcc[a]].insert(b);
                w[a] = b;
                st->modify(1, t, tin[bcc[a] + c], *wi[bcc[a]].begin());
            }
        } else {
            if (a == b) {
                cout << w[a] << endl;
                continue;
            }
            int aid = (cid[a] ? cid[a] : bcc[a] + c);
            int bid = (cid[b] ? cid[b] : bcc[b] + c);
            pair<int, int> pi = lca(aid, bid);
            int ans = pi.first;
            if (pi.second != 1 && pi.second > c) ans = min(ans, st->query(1, t, tin[p[pi.second]], tin[p[pi.second]]));
            cout << ans << endl;
        }
    }
    return 0;
}