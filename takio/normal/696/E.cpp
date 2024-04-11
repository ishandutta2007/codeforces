#include <cstring>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 100010;
const LL INF = 1LL << 60;

vector <int> g[N], h[N];

struct node {
    LL x;
    int y, id;
    node () {}
    node (LL x, int y, int id) : x (x), y (y), id (id) {}
};

int sz[N], son[N], fa[N], top[N], nn, f[N], ed[N], l[N], r[N], p[N], d[N], x[N];
node mx[N << 2];
LL sum[N << 2], lazy[N << 2];

node max (node a, node b) { if (a.x < b.x || a.x == b.x && a.y < b.y) return a; else return b; }

void dfs (int u, int fa, int dep) {
    d[u] = dep;
    sz[u] = 1;
    f[u] = fa;
    son[u] = -1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v, u, dep + 1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2 (int u, int fa, int now) {
//    cout << u << ' ' << fa << ' ' << now << endl;
    l[u] = ++nn;
    p[nn] = u;
    top[u] = now;
    if (son[u] != -1) dfs2 (son[u], u, now);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa || v == son[u]) continue;
//        if (v == son[u])
//        else
        dfs2 (v, u, v);
    }
    r[u] = nn;
}

void build (int rt, int l, int r) {
    sum[rt] = lazy[rt] = 0;
    if (l == r) {
        if (h[p[l]].size ()) mx[rt] = node (h[p[l]][h[p[l]].size() - 1], h[p[l]][h[p[l]].size() - 1], p[l]);
        else mx[rt] = node (INF, 0, 0);
        return;
    }
    int m = l + r >> 1;
    build (lson);
    build (rson);
    mx[rt] = max (mx[ls], mx[rs]);
}

void down (int rt) {
    if (lazy[rt]) {
        sum[ls] += lazy[rt];
        sum[rs] += lazy[rt];
        lazy[ls] += lazy[rt];
        lazy[rs] += lazy[rt];
        mx[ls].x += lazy[rt];
        mx[rs].x += lazy[rt];
        lazy[rt] = 0;
    }
}

void updata (int rt, int l, int r, int tl, int tr, int k) {
    if (tl <= l && r <= tr) {
        if (k == -1) {
            if (ed[p[l]] >= 0) {
                ed[p[l]]--;
                if (ed[p[l]] < 0) mx[rt] = node (INF, 0, 0);
                else mx[rt] = node (sum[rt] + h[p[l]][ed[p[l]]], h[p[l]][ed[p[l]]], p[l]);
            }
        } else {
            sum[rt] += k;
            lazy[rt] += k;
            mx[rt].x += k;
        }
        return;
    }
    down (rt);
    int m = l + r >> 1;
    if (tr <= m) updata (lson, tl, tr, k);
    else if (m < tl) updata (rson, tl, tr, k);
    else updata (lson, tl, m, k), updata (rson, m + 1, tr, k);
    mx[rt] = max (mx[ls], mx[rs]);
}

node query (int rt, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) return mx[rt];
    down (rt);
    int m = l + r >> 1;
    if (tr <= m) return query (lson, tl, tr);
    else if (m < tl) return query (rson, tl, tr);
    else return max (query (lson, tl, m), query (rson, m + 1, tr));
}

bool cmp(int x, int y) { return x > y; }

int main () {
//    freopen ("in.txt", "r", stdin);
//    freopen ("in.txt", "w", stdout);
//    for (int i = 1; i<= 7; i++) for (int j= 1; j <= 7; j++) cout << 1 << ' ' << i << ' ' << j << ' ' << 100 << endl; return 0;
    int n, m, q, t, u, v, k;
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    for (int i = 1; i <= m; i++) {
        scanf ("%d", &x[i]);
        h[x[i]].push_back (i);
    }
    for (int i = 1; i <= n; i++) {
        sort (h[i].begin(), h[i].end(), cmp);
        ed[i] = h[i].size() - 1;
    }
    dfs (1, 1, 1);
    dfs2 (1, 1, 1);
    build (1, 1, n);
//    for (int i = 1; i <= m; i++) updata (1, 1, n, l[x[i]], l[x[i]], i);
    vector <int> ans;
    while (q--) {
        scanf ("%d%d", &t, &u);
//        cout << t << ' ' << u << endl;
        if (t == 1) {
            scanf ("%d%d", &v, &k);
            ans.clear();
            int tu = u, tv = v;
            while (k--) {
                u = tu, v = tv;
                int f1 = top[u], f2 = top[v];
                node res(INF, 0, 0);
                while (f1 != f2) {
//                    cout << f1 << f2 << endl;
                    if (d[f1] < d[f2]) {
                        swap (f1, f2);
                        swap (u, v);
                    }
//                    cout << l[f1] << ' ' << l[u] << endl;
                    res = max (query (1, 1, n, l[f1], l[u]), res);
                    u = f[f1];
                    f1 = top[u];
                }
//                cout << f1 << f2 << endl;
                if (d[u] > d[v]) swap (u, v);
                res = max (query (1, 1, n, l[u], l[v]), res);
                if (res.x == INF) break;
                ans.push_back (res.y);
//                cout << res.x << ' ' << res.y << ' ' << res.id << ' ' << f1 << ' ' << f2 << ' ' << l[res.id] << endl;
                updata (1, 1, n, l[res.id], l[res.id], -1);
            }
            printf ("%d", ans.size());
            for (int i = 0; i < ans.size(); i++) printf (" %d", ans[i]);
            printf ("\n");
        } else {
            scanf ("%d", &k);
            updata (1, 1, n, l[u], r[u], k);
        }
    }
}