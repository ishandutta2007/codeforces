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
const int MAXN = 200200;

int n, e[MAXN][2]; vector <int> E[MAXN];
int fa[MAXN], dfn[MAXN], siz[MAXN], dep[MAXN], wson[MAXN], top[MAXN], cnt;
void dfs1 (int x, int f) {
    fa[x] = f, siz[x] = 1, dep[x] = dep[f] + 1;
    for (auto i: E[x]) if (i != f) 
        dfs1(i, x), siz[x] += siz[i], wson[x] = siz[i] > siz[wson[x]] ? i : wson[x];
}
void dfs2 (int x, int f) {
    dfn[x] = ++cnt; if (!f) top[x] = x;
    if (wson[x]) top[wson[x]] = top[x], dfs2(wson[x], x);
    for (auto i: E[x]) if (i != f && i != wson[x]) top[i] = i, dfs2(i, x);
}

struct node {
    int cnt; ll s, rs;
    node (int _c = 0, ll _s = 0, ll _r = 0) { cnt = _c, s = _s, rs = _r; }
    node operator + (const node &tmp) const { return node(cnt + tmp.cnt, s + tmp.s, rs + tmp.rs); }
} t[MAXN << 2];
bool tag[MAXN << 2];

void add (int pos, int k, int l, int r, int x) {
    if (l == r) { t[x].s = k; return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) add(pos, k, l, mid, x << 1);
    else add(pos, k, mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
void cover (int x, int l, int r) {
    tag[x] ^= 1; t[x].cnt = r - l + 1 - t[x].cnt;
    t[x].rs = t[x].s - t[x].rs;
}
void pushdown (int x, int l, int r) {
    if (tag[x]) {
        int mid = (l + r) >> 1;
        cover(x << 1, l, mid), cover(x << 1 | 1, mid + 1, r);
        tag[x] = 0;
    }
}
void flip (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) { cover(x, L, R); return; }
    int mid = (L + R) >> 1; pushdown(x, L, R);
    if (l <= mid) flip(l, r, L, mid, x << 1);
    if (mid < r) flip(l, r, mid + 1, R, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
void pflip (int u) { while (u) flip(dfn[top[u]], dfn[u], 1, n, 1), u = fa[top[u]]; }

vector <int> res;
void claim (int x, int l, int r) {
    if (l == r) { if (t[x].cnt) res.push_back(t[x].s); return; }
    int mid = (l + r) >> 1; pushdown(x, l, r);
    claim(x << 1, l, mid), claim(x << 1 | 1, mid + 1, r);
}

int val[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i < n; i++) {
        e[i][0] = read(), e[i][1] = read();
        E[e[i][0]].push_back(e[i][1]), E[e[i][1]].push_back(e[i][0]);
    }
    dfs1(1, 0), dfs2(1, 0);
    for (i = 1; i < n; i++) {
        if (fa[e[i][0]] == e[i][1]) val[e[i][0]] = i;
        else val[e[i][1]] = i;
    }
    int cur = 1; pflip(1);
    while (1) {
        int op = read();
        if (op == 1) {
            int x = read(); ++cur;
            add(dfn[x], val[x], 1, n, 1); pflip(x);
            if (t[1].cnt * 2 == cur) printf("%lld\n", t[1].rs);
            else puts("0");
        }
        if (op == 2) {
            if (t[1].cnt * 2 == cur) {
                res.clear();
                claim(1, 1, n); sort(res.begin(), res.end());
                printf("%d ", (int)res.size());
                for (auto i: res) printf("%d ", i);
                putchar('\n');
            }
            else puts("0");
        }
        fflush(stdout);
        if (op == 3) break;
    }
    return 0;
}