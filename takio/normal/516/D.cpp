#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 100100;
const LL INF = 1LL << 60;

int tot, head[N];
LL da[N], db[N], dd[N], d[N], l;

struct edge {
    int v, nx, c;
    edge () {}
    edge (int v, int nx, int c) : v (v), nx (nx), c (c) {}
} e[N * 2];

void add (int u, int v, int d) {
    e[tot] = edge (v, head[u], d);
    head[u] = tot++;
}

void dfs (int u, int fa, LL *d) {
    for (int i = head[u]; ~i; i = e[i].nx) {
        if (e[i].v == fa) continue;
        d[e[i].v] = d[u] + e[i].c;
        dfs (e[i].v, u, d);
    }
}

//int rt, n, s[N], tn, vis[N];
//LL t[N], mn;

//void getrt (int u, int fa) {
//    s[u] = 1;
//    t[++tn] = dd[u];
//    int tmp = 0;
//    for (int i = head[u]; ~i; i = e[i].nx) {
//        int v = e[i].v;
//        if (vis[v] || fa == v) continue;
//        getrt (v, u);
//        s[u] += s[v];
//        tmp = max (tmp, s[v]);
//    }
//    tmp = max (tmp, n - s[u]);
//    if (mn > tmp) mn = tmp, rt = u;
//}
//
//int ans;
//LL l;
//
//void solve (int u) {
//    cout << u << ' ' << endl;
//    vis[u] = 1;
//    tn = 0;
//    getrt (u, 0);
//    sort (t + 1, t + 1 + tn);
//    for (int i = 1; i <= tn; i++) { cout << t[i] << ' ';} cout << endl;
//    for (int i = 1; i <= tn; i++) {
//        if (t[i] - t[])ans = max (ans, i - f + 1);
//        cout <<
//    }
//    for (int i = head[u]; ~i; i = e[i].nx) {
//        if (vis[e[i].v]) continue;
//        mn = INF;
//        tn = 0;
//        getrt (e[i].v, 0);
//        solve (rt);
//    }
//}

int tn, ans, t[N], s[N];

void init () {
    ans = tn = 0;
}

void dfs1 (int u, int fa) {
    t[++tn] = u;
    int ff = 0, ee = tn;
    while (ff + 1 < ee) {
        int m = (ff + ee) >> 1;
        if (dd[u] - dd[t[m]] <= l) ee = m;
        else ff = m;
    }
    s[u] = 1;
    if (ee != 1) s[t[ee - 1]]--;
//    for (int i = 1; i <= tn; i++) cout << t[i] << ' '; cout << endl;
//    cout << ee << endl;
    for (int i = head[u]; ~i; i = e[i].nx) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs1 (v, u);
    }
    tn--;
}

void dfs2 (int u, int fa) {
    for (int i = head[u]; ~i; i = e[i].nx) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs2 (v, u);
        s[u] += s[v];
    }
    ans = max (ans, s[u]);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    memset (head, -1, sizeof head);
    int n;
    cin >> n;
    int u, v, c;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d%d", &u, &v, &c);
        add (u, v, c);
        add (v, u, c);
    }
    dfs (1, 0, d); int mi = 1;
    for (int i = 1; i <= n; i++) if (d[i] > d[mi]) mi = i;
    dfs (mi, 0, da); mi = 1;
    for (int i = 1; i <= n; i++) if (da[i] > da[mi]) mi = i;
    dfs (mi, 0, db);
    int rt = 1;
    for (int i = 1; i <= n; i++) {
        dd[i] = max (da[i], db[i]);
//        cout << i << ' ' << dd[i] << endl;
        if (dd[rt] > dd[i]) rt = i;
    }
    int q;
    cin >> q;
//    cout << rt << endl;
    while (q--) {
        cin >> l;
        init ();
        dfs1 (rt, 0);
        dfs2 (rt, 0);
        cout << ans << endl;
    }
}