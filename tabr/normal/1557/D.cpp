#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = pair<int, int>;
    using F = pair<int, int>;

    T e() {
        return make_pair(0, -1);
    }

    F id() {
        return make_pair(0, -1);
    }

    T op(T a, T b) {
        return max(a, b);
    }

    T mapping(F f, T x) {
        return max(f, x);
    }

    F composition(F f, F g) {
        return max(f, g);
    }

    int n;
    vector<T> node;
    vector<F> lazy;

    segtree() : segtree(0) {}
    segtree(int _n) {
        if (_n <= 1) {
            n = _n;
        } else {
            n = 1 << (32 - __builtin_clz(_n - 1));
        }
        node.resize(2 * n, e());
        lazy.resize(n, id());
    }
    segtree(vector<T> v) {
        if ((int) v.size() <= 1) {
            n = (int) v.size();
        } else {
            n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        }
        node.resize(2 * n, e());
        lazy.resize(n, id());
        for (int i = 0; i < (int) v.size(); i++) {
            node[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            node[i] = op(node[i * 2], node[i * 2 + 1]);
        }
    }

    void eval(int k) {
        node[2 * k] = mapping(lazy[k], node[2 * k]);
        node[2 * k + 1] = mapping(lazy[k], node[2 * k + 1]);
        if (2 * k < n) {
            lazy[2 * k] = composition(lazy[k], lazy[2 * k]);
            lazy[2 * k + 1] = composition(lazy[k], lazy[2 * k + 1]);
        }
        lazy[k] = id();
    }

    void update(int x, int y, F v, int k, int l, int r) {
        if (y <= l || r <= x) {
            return;
        }
        if (x <= l && r <= y) {
            node[k] = mapping(v, node[k]);
            if (k < n) {
                lazy[k] = composition(v, lazy[k]);
            }
        } else {
            eval(k);
            update(x, y, v, 2 * k, l, (l + r) / 2);
            update(x, y, v, 2 * k + 1, (l + r) / 2, r);
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T get(int x, int y, int k, int l, int r) {
        if (y <= l || r <= x) {
            return e();
        }
        if (x <= l && r <= y) {
            return node[k];
        }
        eval(k);
        T vl = get(x, y, 2 * k, l, (l + r) / 2);
        T vr = get(x, y, 2 * k + 1, (l + r) / 2, r);
        return op(vl, vr);
    }

    void update(int x, int y, F v) {
        update(x, y, v, 1, 0, n);
    }

    T get(int x, int y) {
        return get(x, y, 1, 0, n);
    }

    T get(int x) {
        return get(x, x + 1, 1, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> s(n);
    for (int i = 0; i < m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        x--;
        s[x].emplace_back(l, r);
    }
    for (int i = 0; i < n; i++) {
        if (s[i].empty()) {
            continue;
        }
        sort(s[i].begin(), s[i].end());
        vector<pair<int, int>> new_s;
        for (auto [l, r] : s[i]) {
            if (new_s.empty()) {
                new_s.emplace_back(l, r);
                continue;
            }
            if (new_s.back().second >= l - 1) {
                new_s.back().second = max(new_s.back().second, r);
            } else {
                new_s.emplace_back(l, r);
            }
        }
        swap(s[i], new_s);
    }
    vector<int> comp;
    for (auto v : s) {
        for (auto [l, r] : v) {
            comp.emplace_back(l);
            comp.emplace_back(r + 1);
        }
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for (auto &v : s) {
        for (auto &[l, r] : v) {
            l = (int) (lower_bound(comp.begin(), comp.end(), l) - comp.begin());
            r = (int) (lower_bound(comp.begin(), comp.end(), r + 1) - comp.begin());
        }
    }
    debug(s);
    segtree seg((int) comp.size());
    vector<int> a(n, 1), pre(n, -1);
    for (int i = 0; i < n; i++) {
        if (s[i].empty()) {
            continue;
        }
        pair<int, int> p(0, -1);
        for (auto [l, r] : s[i]) {
            p = max(p, seg.get(l, r));
        }
        p.first++;
        tie(a[i], pre[i]) = p;
        p.second = i;
        for (auto [l, r] : s[i]) {
            seg.update(l, r, p);
        }
    }
    debug(a);
    debug(pre);
    int id = (int) (max_element(a.begin(), a.end()) - a.begin());
    vector<int> ng;
    for (int i = n - 1; i > id; i--) {
        ng.emplace_back(i);
    }
    while (id != -1) {
        for (int i = id - 1; i > pre[id]; i--) {
            ng.emplace_back(i);
        }
        id = pre[id];
    }
    reverse(ng.begin(), ng.end());
    cout << ng.size() << '\n';
    for (int i : ng) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}