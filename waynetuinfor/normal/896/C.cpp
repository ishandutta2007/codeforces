#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int inf = 1e9 + 1;
int a[maxn], op[maxn], l[maxn], r[maxn], x[maxn], y[maxn];
int seed, vmax;

int rnd() {
    int ret = seed;
    seed = (seed * 1ll * 7 + 13) % 1000000007;
    return ret;
}

void predo(int n, int m) {
    for (int i = 1; i <= n; ++i) a[i] = rnd() % vmax + 1;
    for (int i = 0; i < m; ++i) {
        op[i] = rnd() % 4 + 1;
        l[i] = rnd() % n + 1;
        r[i] = rnd() % n + 1;
        if (l[i] > r[i]) swap(l[i], r[i]);
        if (op[i] == 3) x[i] = rnd() % (r[i] - l[i] + 1) + 1;
        else x[i] = rnd() % vmax + 1;
        if (op[i] == 4) y[i] = rnd() % vmax + 1;
    }
}

struct data {
    int l, r; long long v;
    data(int a, int b, long long c): l(a), r(b), v(c) {}
    bool operator<(const data &d) const { return tie(l, r, v) < tie(d.l, d.r, d.v); }
    bool operator==(const data &d) const { return tie(l, r, v) == tie(d.l, d.r, d.v); }
};

set<data> s;

void range_add(int l, int r, int x) {
    auto it = prev(s.upper_bound(data(l, inf, 0)));
    if (it->l <= l && it->r >= r) {
        vector<data> todo;
        todo.emplace_back(l, r, it->v + x);
        if (l - 1 >= it->l) todo.emplace_back(it->l, l - 1, it->v);
        if (r + 1 <= it->r) todo.emplace_back(r + 1, it->r, it->v);
        it = s.erase(it);
        for (int i = 0; i < todo.size(); ++i) s.insert(todo[i]);
        return;
    }
    vector<data> todo;
    if (it->r >= l) todo.emplace_back(l, it->r, it->v + x);
    if (l - 1 >= it->l) todo.emplace_back(it->l, l - 1, it->v);
    it = s.erase(it);
    while (it != s.end()) {
        if (it->l > r) break;
        if (it->r <= r) {
            todo.emplace_back(it->l, it->r, it->v + x);
            it = s.erase(it);
        } else {
            if (r >= it->l) todo.emplace_back(it->l, r, it->v + x);
            if (it->r > r) todo.emplace_back(r + 1, it->r, it->v);
            s.erase(data(it->l, it->r, it->v));
            break;
        }
    }
    for (int i = 0; i < todo.size(); ++i) s.insert(todo[i]);
} 

void range_set(int l, int r, int x) {
    auto it = prev(s.upper_bound(data(l, inf, 0)));
    if (it->l <= l && it->r >= r) {
        vector<data> todo;
        todo.emplace_back(l, r, x);
        if (l - 1 >= it->l) todo.emplace_back(it->l, l - 1, it->v);
        if (r + 1 <= it->r) todo.emplace_back(r + 1, it->r, it->v);
        it = s.erase(it);
        for (int i = 0; i < todo.size(); ++i) s.insert(todo[i]);
        return;
    }
    int ql = l, qr = r;
    vector<data> todo;
    if (l - 1 >= it->l) {
        if (it->v == x) ql = it->l;
        else todo.emplace_back(it->l, l - 1, it->v);
        it = s.erase(it);
    }
    while (it != s.end()) {
        if (it->l > r) break;
        if (it->r <= r) {
            it = s.erase(it);
        } else {
            if (it->r > r) {
                if (it->v == x) qr = it->r;
                else todo.emplace_back(r + 1, it->r, it->v);
                s.erase(it);
            }
            break;
        }
    }
    todo.emplace_back(ql, qr, x);
    for (int i = 0; i < todo.size(); ++i) s.insert(todo[i]);
}

long long xquery(int l, int r, int x) {
    assert(x >= 1 && x <= r - l + 1);
    auto it = prev(s.upper_bound(data(l, inf, 0)));
    if (it->l <= l && it->r >= r) return it->v;
    vector<pair<long long, int>> seg;
    seg.emplace_back(it->v, it->r - l + 1);
    ++it;
    while (it != s.end()) {
        if (it->l > r) break;
        if (it->r <= r) {
            seg.emplace_back(it->v, it->r - it->l + 1);
            ++it;
        } else {
            seg.emplace_back(it->v, r - it->l + 1);
            break;
        }
    }
    sort(seg.begin(), seg.end());
    int t = 0;
    for (int i = 0; i < seg.size(); ++i) {
        if (t < x && t + seg[i].second >= x) return seg[i].first;
        t += seg[i].second;
    }
    assert(false);
}

int fpow(int a, int n, int p) {
    a %= p;
    int r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * 1ll * a % p;
        a = a * 1ll * a % p;
    }
    return r;
}

long long pquery(int l, int r, int x, int y) {
    auto it = prev(s.upper_bound(data(l, inf, 0)));
    if (it->l <= l && it->r >= r) return fpow(it->v % y, x, y) * 1ll * (r - l + 1) % y;
    int ans = 0;
    (ans += fpow(it->v % y, x, y) * 1ll * (it->r - l + 1) % y) %= y;
    ++it;
    while (it != s.end()) {
        if (it->l > r) break;
        if (it->r <= r) {
            (ans += fpow(it->v % y, x, y) * 1ll * (it->r - it->l + 1) % y) %= y;
            ++it;
        } else {
            (ans += fpow(it->v % y, x, y) * 1ll * (r - it->l + 1) % y) %= y;
            break;
        }
    }
    return ans;
}

int main() {
    int n, m; scanf("%d %d %d %d", &n, &m, &seed, &vmax);
    predo(n, m);
    for (int i = 1; i <= n; ) {
        int j = i;
        while (j <= n && a[j] == a[i]) ++j;
        s.insert(data(i, j - 1, a[i]));
        i = j;
    }
    for (int i = 0; i < m; ++i) {
        if (op[i] == 1) range_add(l[i], r[i], x[i]);
        if (op[i] == 2) range_set(l[i], r[i], x[i]);
        if (op[i] == 3) printf("%lld\n", xquery(l[i], r[i], x[i]));
        if (op[i] == 4) printf("%lld\n", pquery(l[i], r[i], x[i], y[i]));
    }
    return 0;
}