#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

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
const int lim = 1e5, MAXN = lim + 100;
int n, m;
namespace seg1 {
    ll t[MAXN << 2], tag0[MAXN << 2], tag1[MAXN << 2];
    void pushup (int x) { t[x] = t[x << 1] + t[x << 1 | 1]; }
    void cover0 (int x, ll k, int l, int r) { tag0[x] += k, t[x] += k * (r - l + 1); }
    void cover1 (int x, ll k, int l, int r) { tag1[x] += k, t[x] += k * (1ll * (l + r) * (r - l + 1) / 2); }
    void pushdown (int x, int l, int r) {
        int mid = (l + r) >> 1;
        if (tag0[x]) cover0(x << 1, tag0[x], l, mid), cover0(x << 1 | 1, tag0[x], mid + 1, r), tag0[x] = 0;
        if (tag1[x]) cover1(x << 1, tag1[x], l, mid), cover1(x << 1 | 1, tag1[x], mid + 1, r), tag1[x] = 0;
    }
    void modify (bool op, int l, int r, ll k, int L, int R, int x) {
        // if (x == 1) printf("modify (%d) %d %d %lld\n", op, l, r, k);
        if (l > r) return;
        if (l <= L && R <= r) { if (!op) cover0(x, k, L, R); else cover1(x, k, L, R); return; }
        int mid = (L + R) >> 1; pushdown(x, L, R);
        if (l <= mid) modify(op, l, r, k, L, mid, x << 1);
        if (mid < r) modify(op, l, r, k, mid + 1, R, x << 1 | 1);
        pushup(x);
    }
    ll query (int pos, int l, int r, int x) {
        if (l > r) return 0;
        if (l == r) return t[x];
        int mid = (l + r) >> 1; pushdown(x, l, r);
        if (pos <= mid) return query(pos, l, mid, x << 1);
        else return query(pos, mid + 1, r, x << 1 | 1);
    }
    void clear (int l, int r, int x) {
        t[x] = tag0[x] = tag1[x] = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        clear(l, mid, x << 1), clear(mid + 1, r, x << 1 | 1);
    }
}

void modify (int i, int nex, int k) {
    // printf("modify1 %d %d %d\n", i, nex, k);
    --nex;
    seg1::modify(0, 1, nex, 1ll * k * (nex - i + 1), 1, n, 1);
    seg1::modify(0, i + 1, nex, 1ll * k * i, 1, n, 1);
    seg1::modify(1, i + 1, nex, -k, 1, n, 1);
    seg1::modify(0, 1, nex - i + 1, -1ll * k * (nex - i + 1), 1, n, 1);
    seg1::modify(1, 1, nex - i + 1, k, 1, n, 1);
}
void modify2 (int l, int r, int k) {
    // printf("modify2 %d %d %d\n", l, r, k);
    --l, --r;
    seg1::modify(0, 1, l, 1ll * k * (r - l), 1, n, 1);
    seg1::modify(0, l + 1, r, 1ll * k * (r + 1), 1, n, 1);
    seg1::modify(1, l + 1, r, -k, 1, n, 1);
}

struct foo {
    int pos, len, col;
    foo () {}
    foo (int _pos, int _len, int _col): pos(_pos), len(_len), col(_col) {}
    bool operator < (const foo &other) const {
        return pos < other.pos;
    }
};
set <foo> s[MAXN], S;
void split (int pos) { // [l, r] -> [l, pos - 1], [pos, r]
    if (pos > n) return;
    auto it = S.upper_bound(foo(pos, 0, 0)); --it;
    if ((*it).pos < pos) {
        foo now = *it;
        s[(*it).col].erase(now); S.erase(it);
        S.insert(foo(now.pos, pos - now.pos, now.col)); S.insert(foo(pos, now.len - (pos - now.pos), now.col));
        s[now.col].insert(foo(now.pos, pos - now.pos, now.col)); s[now.col].insert(foo(pos, now.len - (pos - now.pos), now.col));
    }
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) {
        int x = read();
        s[x].insert(foo(i, 1, x)), S.insert(foo(i, 1, x));
    }
    for (i = 1; i <= lim; i++) {
        s[i].insert(foo(n + 1, 0, 0));
        auto it = s[i].begin();
        while (1) {
            j = (*it).pos, ++it;
            if (it == s[i].end()) break;
            modify(j, (*it).pos, 1);
        }
    }
    while (m--) {
        int op = read();
        if (op == 1) {
            int l = read(), r = read(), x = read();
            split(l), split(r + 1);
            auto it = S.upper_bound(foo(l - 1, 0, 0));
            while (it != S.end() && (*it).pos <= r) {
                foo now = *it; S.erase(it); it = s[now.col].find(now);
                modify2(now.pos, now.pos + now.len - 1, -1);
                ++it; int nex = (*it).pos; --it;
                modify(now.pos + now.len - 1, nex, -1);
                if (it != s[now.col].begin()) {
                    --it; modify((*it).pos + (*it).len - 1, now.pos, -1);
                    modify((*it).pos + (*it).len - 1, nex, 1); ++it;
                }
                s[now.col].erase(it);
                it = S.upper_bound(foo(l - 1, 0, 0));
            }
            modify2(l, r, 1);
            it = s[x].upper_bound(foo(l - 1, 0, 0)); int nex = (*it).pos; modify(r, nex, 1);
            if (it != s[x].begin()) { --it; modify((*it).pos + (*it).len - 1, nex, -1); modify((*it).pos + (*it).len - 1, l, 1); }
            S.insert(foo(l, r - l + 1, x)); s[x].insert(foo(l, r - l + 1, x));
        }
        if (op == 2) { int x = read(); printf("%lld\n", seg1::query(x, 1, n, 1)); }
    }
    // printf("? %d %d\n", cnt1, cnt2);
    return 0;
}