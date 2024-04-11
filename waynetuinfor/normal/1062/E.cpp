#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int euler[maxn * 10], dep[maxn], tin[maxn], tk;
int st[20][maxn * 10], tl[20][maxn], tr[20][maxn];

void dfs(int x, int p) {
    dep[x] = ~p ? dep[p] + 1 : 0;
    tin[x] = tk;
    euler[tk++] = x;
    for (const int &u : g[x]) {
        dfs(u, x);
        euler[tk++] = x;
    }
}

int queryl(int l, int r) {
    if (l == r) return -1;
    int p = 31 - __builtin_clz(r - l);
    return tin[tl[p][l]] < tin[tl[p][r - (1 << p)]] ? 
           tl[p][l] : tl[p][r - (1 << p)];
}

int queryr(int l, int r) {
    if (l == r) return -1;
    int p = 31 - __builtin_clz(r - l);
    return tin[tr[p][l]] > tin[tr[p][r - (1 << p)]] ? 
           tr[p][l] : tr[p][r - (1 << p)];
}

int query(int l, int r) {
    if (l == r) return -1;
    int p = 31 - __builtin_clz(r - l);
    return dep[st[p][l]] < dep[st[p][r - (1 << p)]] ? 
           st[p][l] : st[p][r - (1 << p)];
}

int solve(int x, int l, int r) {
    int ll = queryl(l, x), lr = queryr(l, x);
    int rl = queryl(x + 1, r + 1), rr = queryr(x + 1, r + 1);
    int pl = (ll == -1 ? rl : (rl == -1 ? ll : (tin[ll] < tin[rl] ? ll : rl)));
    int pr = (lr == -1 ? rr : (rr == -1 ? lr : (tin[lr] > tin[rr] ? lr : rr)));
    return query(tin[pl], tin[pr] + 1);
}

int main() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int p; scanf("%d", &p);
        g[p - 1].push_back(i);
    }
    dfs(0, -1);
    for (int i = 0; i < tk; ++i) st[0][i] = euler[i];
    for (int i = 1; (1 << i) <= tk; ++i) {
        for (int j = 0; j + (1 << i) <= tk; ++j)
            st[i][j] = dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << (i - 1))]] ?
                       st[i - 1][j] : st[i - 1][j + (1 << (i - 1))];
    }
    for (int i = 0; i < n; ++i) tl[0][i] = tr[0][i] = i;
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << i) <= tk; ++j) {
            tl[i][j] = tin[tl[i - 1][j]] < tin[tl[i - 1][j + (1 << (i - 1))]] ? 
                       tl[i - 1][j] : tl[i - 1][j + (1 << (i - 1))];
            tr[i][j] = tin[tr[i - 1][j]] > tin[tr[i - 1][j + (1 << (i - 1))]] ? 
                       tr[i - 1][j] : tr[i - 1][j + (1 << (i - 1))];
        }
    }
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        --l, --r;
        int x = queryl(l, r + 1), y = queryr(l, r + 1);
        int p = solve(x, l, r), q = solve(y, l, r);
        if (dep[p] > dep[q]) printf("%d %d\n", x + 1, dep[p]);
        else printf("%d %d\n", y + 1, dep[q]);
    }
    return 0;
}