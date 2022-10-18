#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    using T = tuple<int, int, int>;
    int n;
    int h;
    vector<vector<T>> table;

    T op(T x, T y) {
        auto [x0, x1, x2] = x;
        auto [y0, y1, y2] = y;
        auto p = min(make_pair(x1, x2), make_pair(y1, y2));
        return make_tuple(max(x0, y0), p.first, p.second);
    }

    sparse(const vector<T> &v) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int l, int r) {
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int, int>> qs(q);
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            qs[i] = make_tuple(op, l, r, x);
        } else {
            int j;
            cin >> j;
            j--;
            qs[i] = make_tuple(op, j, -1, -1);
        }
    }
    set<int> ok;
    for (int i = 0; i <= n; i++) {
        ok.emplace(i);
    }
    vector<int> when(n, -1);
    for (int it = 0; it < q; it++) {
        auto [op, l, r, x] = qs[it];
        if (op == 1 || x == 1) {
            continue;
        }
        int i = *ok.lower_bound(l);
        while (i < r) {
            when[i] = it;
            ok.erase(i);
            i = *ok.lower_bound(i);
        }
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (when[i] == -1);
    }
    vector<vector<int>> cy(q), cn(q);
    for (int i = 0; i < n; i++) {
        if (when[i] != -1) {
            cn[when[i]].emplace_back(i);
        }
    }
    vector<tuple<int, int, int>> sdef(n);
    for (int i = 0; i < n; i++) {
        sdef[i] = make_tuple(when[i], when[i], i);
    }
    sparse sp(sdef);
    for (int it = 0; it < q; it++) {
        auto [op, l, r, x] = qs[it];
        if (op == 0 && x == 1 && pref[l] + 1 == pref[r]) {
            auto [v0, v1, v2] = sp.get(l, r);
            cy[max(it, v0)].emplace_back(v2);
        }
    }
    set<int> yes;
    set<int> no;
    for (int it = 0; it < q; it++) {
        for (int i : cy[it]) {
            yes.emplace(i);
        }
        for (int i : cn[it]) {
            no.emplace(i);
        }
        if (get<0>(qs[it]) == 1) {
            int j = get<1>(qs[it]);
            if (yes.count(j)) {
                cout << "YES" << '\n';
            } else if (no.count(j)) {
                cout << "NO" << '\n';
            } else {
                cout << "N/A" << '\n';
            }
        }
    }
    debug(yes);
    debug(no);
    return 0;
}