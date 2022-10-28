#include <bits/stdc++.h>
using namespace std;

struct segtree {
    vector<long long> tree, lazy;
    int n;

    segtree(int n) : n(n) {
        tree.resize(4 * n), lazy.resize(4 * n);
    }

    void apply(int u, int len, long long x) {
        tree[u] += x * len, lazy[u] += x;
    }

    void push(int u, int len) {
        if (lazy[u]) {
            apply(2 * u, (len + 1) / 2, lazy[u]);
            apply(2 * u + 1, len / 2, lazy[u]);
            lazy[u] = 0;
        }
    }

    void update(int a, int b, long long x, int u, int l, int r) {
        if (a <= l && r <= b) {
            apply(u, r - l + 1, x);
        } else if (b < l || r < a) {
            return;
        } else {
            push(u, r - l + 1);
            int m = (l + r) / 2;
            update(a, b, x, 2 * u, l, m);
            update(a, b, x, 2 * u + 1, m + 1, r);
            tree[u] = tree[2 * u] + tree[2 * u + 1];
        }
    }

    long long query(int a, int b, int u, int l, int r) {
        if (a <= l && r <= b) return tree[u];
        if (b < l || r < a) return 0;

        push(u, r - l + 1);
        int m = (l + r) / 2;
        return query(a, b, 2 * u, l, m) + query(a, b, 2 * u + 1, m + 1, r);
    }

    void update(int a, int b, long long x) {
        update(a, b, x, 1, 0, n - 1);
    }

    long long query(int a, int b) {
        return query(a, b, 1, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    vector<int> p(n);
    for (auto &i : p) cin >> i;

    vector<int> position(n + 1);
    for (int i = 0; i < n; ++i) position[p[i]] = i;

    vector<vector<int>> divisors(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divisors[j].push_back(i);
        }
    }

    set<int> bounds = {-1, n};
    vector<vector<array<int, 3>>> borders(n + 1);
    for (int max_p = n; max_p > 0; --max_p) {
        auto it = bounds.insert(position[max_p]).first;
        int l = *prev(it) + 1, m = *it, r = *next(it) - 1;

        vector<pair<int, int>> segments;
        for (int d : divisors[max_p]) {
            int i = position[d], j = position[max_p / d];
            if (l <= i && i < j && j <= r)
                segments.push_back({min(i, m), max(j, m)});
        }
        sort(segments.begin(), segments.end());

        vector<pair<int, int>> relevant = {{l - 1, -1}};
        for (auto [a, b] : segments) {
            if (relevant.back().first == a) continue;
            while (relevant.back().second >= b) relevant.pop_back();
            relevant.push_back({a, b});
        }

        for (int i = 1; i < (int) relevant.size(); ++i) {
            int x1 = relevant[i - 1].first + 1, x2 = relevant[i].first;
            int y1 = relevant[i].second, y2 = r;
            borders[y1].push_back({x1, x2, 1});
            borders[y2 + 1].push_back({x1, x2, -1});
        }
    }

    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; ++i) {
        auto &[r, l, id] = queries[i];
        cin >> l >> r, --l, --r;
        id = i;
    }
    sort(queries.begin(), queries.end());

    int ptr = 0;
    vector<long long> answer(q);
    segtree segtree_m(n), segtree_b(n);
    for (auto [r, l, id] : queries) {
        while (ptr <= r) {
            for (auto [a, b, k] : borders[ptr]) {
                segtree_m.update(a, b, k);
                segtree_b.update(a, b, -k * (ptr - 1));
            }
            ++ptr;
        }
        answer[id] = segtree_m.query(l, r) * r + segtree_b.query(l, r);
    }

    for (auto i : answer) cout << i << "\n";
}