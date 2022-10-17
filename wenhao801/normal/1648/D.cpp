#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#define ll long long
#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 500500;
const ll inf = 1e18;

int n, q; ll a[MAXN], b[MAXN], c[MAXN], f[MAXN];
vector <pii> event[MAXN];

struct node {
    ll maxans, maxk, maxf;
    node (ll _ans = -inf, ll _k = -inf, ll _f = -inf) { maxans = _ans, maxk = _k, maxf = _f; }
    node operator + (const node &other) const {
        return node(
            max({maxans, other.maxans, maxk + other.maxf}),
            max(maxk, other.maxk),
            max(maxf, other.maxf)
        );
    }
} t[MAXN << 2];
multiset <ll> s[MAXN];

void modify (int pos, ll k, int l, int r, int x) {
    if (l == r) {
        if (k > 0) s[l].erase(s[l].find(-k));
        else s[l].insert(k);
        t[x].maxk = *(--s[l].end()); t[x].maxans = max(-inf, t[x].maxf + t[x].maxk);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(pos, k, l, mid, x << 1);
    else modify(pos, k, mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}

void f_modify (int pos, ll k, int l, int r, int x) {
    if (l == r) {
        t[x].maxf = max(t[x].maxf, k);
        t[x].maxans = max(-inf, t[x].maxf + t[x].maxk);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) f_modify(pos, k, l, mid, x << 1);
    else f_modify(pos, k, mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}

int main () {
    n = read(), q = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= n; i++) b[i] = read();
    for (i = 1; i <= n; i++) c[i] = read();
    for (i = n; i >= 1; i--) c[i] += c[i + 1];
    for (i = 1; i <= n; i++) b[i] += b[i - 1], a[i] += a[i - 1], s[i].insert(-inf);
    for (i = n; i >= 1; i--) a[i] = a[i] - b[i] + (b[i] - b[i - 1]);

    for (i = 1; i <= q; i++) {
        int l = read(), r = read(), k = -read();
        event[l].emplace_back(l, k), event[r + 1].emplace_back(l, -k);
    }
    ll ans = -inf;
    for (i = 1; i <= n; i++) {
        for (auto e: event[i]) modify(e.fr, e.se, 1, n, 1);
        f_modify(i, a[i], 1, n, 1);
        f[i] = t[1].maxans; ans = max(ans, f[i] + b[i] + c[i]);
        if (i < n) f_modify(i + 1, f[i], 1, n, 1);
    }
    printf("%lld\n", ans);
    return 0;
}