#include <bits/stdc++.h>
using namespace std;

struct segtree {
    segtree *left, *right;
    int min_value, lazy_add;

    segtree(int l, int r) {
        if (r - l > 1) {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m, r); 
            pull();
        } else {
            min_value = 0;
        }
        lazy_add = 0;
    }

    void update(int a, int b, int x, int l, int r) {
        if (a <= l && r <= b) apply(x);
        else if (b <= l || r <= a) return;
        else {
            push();
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m, r);
            pull();
        }
    }

    void apply(int x) {
        min_value += x, lazy_add += x;
    }

    void push() {
        if (lazy_add != 0) {
            left->apply(lazy_add), right->apply(lazy_add);
            lazy_add = 0;
        }
    }

    void pull() {
        min_value = min(left->min_value, right->min_value);
    }
};

template <class T>
struct fenwick_tree {
    fenwick_tree(int n = 0) : n(n) {
        tree.resize(n + 1);
    }

    void update(int i, T x) {
        if (i > n) return;
        tree[i] += x;
        update(i + (i & -i), x);
    }

    T operator()(int i) {
        if (i == 0) return T(0);
        return tree[i] + (*this)(i - (i & -i));
    }

    vector<T> tree;
    int n;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        vector<int> b(m);
        for (auto &i : b) cin >> i;

        vector<pair<int, int>> events;
        for (int i = 0; i < n; ++i)
            events.push_back({a[i], i});
        for (auto i : b)
            events.push_back({i, -1});
        sort(events.begin(), events.end());

        segtree *range_min = new segtree(0, n + 1);
        for (int i = 0; i < n; ++i) {
            range_min->update(i + 1, n + 1, 1, 0, n + 1);
        }

        long long answer = 0;
        for (int i = 0, j = 0; i < (int) events.size(); i = j) {
            while (j < (int) events.size() && events[i].first == events[j].first) ++j;
            for (int k = i; k < j; ++k) {
                auto [x, y] = events[k];
                if (y >= 0)
                    range_min->update(y + 1, n + 1, -1, 0, n + 1);
            }
            for (int k = i; k < j; ++k) {
                auto [x, y] = events[k];
                if (y == -1)
                    answer += range_min->min_value;
                else
                    range_min->update(0, y + 1, 1, 0, n + 1);
            }
        }

        vector<int> values = a;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        fenwick_tree<int> fenw(n);
        for (int i = 0; i < n; ++i) {
            a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
            answer += fenw(n) - fenw(a[i] + 1);
            fenw.update(a[i] + 1, 1);
        }

        cout << answer << "\n";
    }
}