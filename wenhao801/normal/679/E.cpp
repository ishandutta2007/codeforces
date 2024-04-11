#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ll long long

int n, q; ll p42[11];

const int MAXN = 400400;
const ll inf = 1e18;

ll t[MAXN][11], tag[MAXN], addtag[MAXN];
bool leaf[MAXN];

void pushup (int x) { for (int i = 0; i <= 10; i++) t[x][i] = min(t[x << 1][i], t[x << 1 | 1][i]); }

void build (int l, int r, int x) {
    if (l == r) {
        leaf[x] = 1; ll val = read();
        for (int i = 0; i <= 10; i++) t[x][i] = inf;
        for (int i = 10; i >= 0; i--) if (p42[i] < val) { t[x][i + 1] = p42[i + 1] - val; break; }
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
    pushup(x);
}

void cover (int x, ll k) {
    tag[x] = k; addtag[x] = 0;
    for (int i = 0; i <= 10; i++) t[x][i] = inf;
    for (int i = 10; i >= 0; i--) if (p42[i] < k) { t[x][i + 1] = p42[i + 1] - k; break; }
}

void add (int x, ll k) {
    if (tag[x]) tag[x] += k;
    addtag[x] += k;
    for (int i = 0; i <= 10; i++) if (t[x][i] != inf) t[x][i] -= k;
}

void pushdown (int x) {
    if (tag[x]) {
        cover(x << 1, tag[x]); cover(x << 1 | 1, tag[x]);
        tag[x] = addtag[x] = 0;
    }
    else if (addtag[x]) {
        add(x << 1, addtag[x]); add(x << 1 | 1, addtag[x]);
        addtag[x] = 0;
    }
}

ll query (int pos, int l, int r, int x) {
    if (l == r) { for (int i = 0; i <= 10; i++) if (t[x][i] != inf) return p42[i] - t[x][i]; }
    int mid = (l + r) >> 1; pushdown(x);
    if (pos <= mid) return query(pos, l, mid, x << 1);
    else return query(pos, mid + 1, r, x << 1 | 1);
}

void modify1 (int l, int r, int k, int L, int R, int x) {
    if (l <= L && R <= r) { cover(x, k); return; }
    int mid = (L + R) >> 1; pushdown(x);
    if (l <= mid) modify1(l, r, k, L, mid, x << 1);
    if (mid < r) modify1(l, r, k, mid + 1, R, x << 1 | 1);
    pushup(x);
}

bool judge () { for (int i = 0; i <= 10; i++) if (!t[1][i]) return 1; return 0; }

void deb (int x) { printf("node %d: tag = %lld, add = %lld, t[1] = %lld, t[2] = %lld\n", x, tag[x], addtag[x], t[x][1], t[x][2]); }
void dfs (int x) {
    if (leaf[x] || tag[x]) {
        for (int i = 9; i >= 0; i--) if (t[x][i] < 0) {
            ll val = p42[i] - t[x][i]; t[x][i] = inf;
            for (int j = i + 1; j <= 10; j++) if (p42[j] >= val) { t[x][j] = min(t[x][j], p42[j] - val); break; }
        }
        return;
    }
    for (int i = 0; i <= 10; i++) if (t[x][i] < 0) {
        pushdown(x);
        dfs(x << 1); dfs(x << 1 | 1);
        pushup(x); return;
    }
}

void modify2 (int l, int r, int k, int L, int R, int x) {
    if (l <= L && R <= r) { add(x, k), dfs(x); return; }
    int mid = (L + R) >> 1; pushdown(x);
    if (l <= mid) modify2(l, r, k, L, mid, x << 1);
    if (mid < r) modify2(l, r, k, mid + 1, R, x << 1 | 1);
    pushup(x);
}

int main () {
    n = read(), q = read(); int i, j;
    p42[0] = 1; for (i = 1; i <= 10; i++) p42[i] = 42ll * p42[i - 1];
    build(1, n, 1);
    while (q--) {
        int op = read();
        if (op == 1) { int x = read(); printf("%lld\n", query(x, 1, n, 1)); }
        if (op == 2) { int l = read(), r = read(), k = read(); modify1(l, r, k, 1, n, 1); }
        if (op == 3) {
            int l = read(), r = read(), k = read();
            do { modify2(l, r, k, 1, n, 1); } while (judge());
        }
        // printf("now: "); for (int i = 1; i <= n; i++) printf("%lld ", query(i, 1, n, 1)); puts("");
    }
    return 0;
}