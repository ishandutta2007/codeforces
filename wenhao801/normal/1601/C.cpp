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
const int MAXN = 1001000;
int n, m, a[MAXN], b[MAXN], top;
int Hash (int x) { return lower_bound(b + 1, b + top + 1, x) - b; }

ll ans[MAXN], acc[MAXN]; vector <int> pos[MAXN];

ll t[MAXN << 2], tag[MAXN << 2];
void build (int l, int r, int x) {
    t[x] = tag[x] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
}
void cover (int x, ll k, int l, int r) { t[x] += k; tag[x] += k; }
void pushup (int x) { t[x] = min(t[x << 1], t[x << 1 | 1]); }
void pushdown (int x, int l, int r) {
    if (tag[x]) {
        int mid = (l + r) >> 1;
        cover(x << 1, tag[x], l, mid);
        cover(x << 1 | 1, tag[x], mid + 1, r);
        tag[x] = 0;
    }
}
int query (int pos, int l, int r, int x) {
    if (l == r) return t[x];
    int mid = (l + r) >> 1; pushdown(x, l, r);
    if (pos <= mid) return query(pos, l, mid, x << 1);
    else return query(pos, mid + 1, r, x << 1 | 1);
    pushup(x);
}
void modify (int l, int r, ll k, int L, int R, int x) {
    if (l <= L && R <= r) { cover(x, k, L, R); return; }
    int mid = (L + R) >> 1; pushdown(x, L, R);
    if (l <= mid) modify(l, r, k, L, mid, x << 1);
    if (mid < r) modify(l, r, k, mid + 1, R, x << 1 | 1);
    pushup(x);
}

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read(); int i, j;
        build(0, n, 1);
        for (i = 1; i <= n; i++) a[i] = read(), b[++top] = a[i], modify(i, n, 1, 0, n, 1);
        sort(b + 1, b + top + 1); top = unique(b + 1, b + top + 1) - b - 1;
        b[++top] = 1e9 + 7;
        ll out = 0;
        for (i = 1; i <= n; i++) pos[Hash(a[i])].push_back(i);
        for (i = 0; i < top; i++) {
            for (auto j: pos[i]) modify(j, n, -1, 0, n, 1);
            acc[i] = t[1];
            for (auto j: pos[i]) out += query(j, 0, n, 1);
            for (auto j: pos[i]) modify(0, j - 1, 1, 0, n, 1);
            ans[i] = t[1];
        }
        out >>= 1;
        while (m--) {
            int x = read(), tmp = Hash(x);
            if (b[tmp] == x) out += acc[tmp];
            else out += ans[tmp - 1];
        }
        printf("%lld\n", out);
        for (i = 1; i <= n; i++) modify(0, i - 1, 1, 0, n, 1);
        for (i = 1; i <= top; i++) pos[i].clear();
        top = 0;
    }
    return 0;
}