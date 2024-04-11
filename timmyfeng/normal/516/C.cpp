#include <bits/stdc++.h>
using namespace std;

array<long long, 3> merge(const array<long long, 3> &l, const array<long long, 3> &r) {
    return {
        max(l[0], r[0]),
        max(l[1], r[1]),
        max({l[2], r[2], min(l[0], r[1]) > LLONG_MIN ? l[0] + r[1] : LLONG_MIN})
    };
}

struct segtree {
    array<long long, 3> value;
    segtree *left, *right;

    segtree(int l, int r, long long *x, long long *y) {
        if (l == r) {
            value = {x[l], y[l], LLONG_MIN};
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m, x, y);
            right = new segtree(m + 1, r, x, y);
            value = merge(left->value, right->value);
        }
    }

    array<long long, 3> query(int a, int b, int l, int r) {
        if (l > r || b < l || r < a) {
            return {LLONG_MIN, LLONG_MIN, LLONG_MIN};
        } else if (a <= l && r <= b) {
            return value;
        } else {
            int m = (l + r) / 2;
            return merge(left->query(a, b, l, m), right->query(a, b, m + 1, r));
        }
    }
};

const int N = 100000;

long long dist[N], height[N], prefix[N], suffix[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> dist[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    long long total_dist = 0;
    for (int i = 0; i < n; ++i) {
        prefix[i] = 2 * height[i] - total_dist;
        total_dist += dist[i];
    }

    total_dist = 0;
    for (int i = n - 1; i >= 0; --i) {
        total_dist += dist[i];
        suffix[i] = 2 * height[i] - total_dist;
    }

    segtree *park = new segtree(0, n - 1, prefix, suffix);

    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        if (b < a) {
            cout << park->query(b + 1, a - 1, 0, n - 1)[2] + total_dist << "\n";
        } else {
            array<long long, 3> l = park->query(0, a - 1, 0, n - 1);
            array<long long, 3> r = park->query(b + 1, n - 1, 0, n - 1);
            cout << max({
                max(l[2], r[2]) + total_dist,
                r[0] + l[1] + 2 * total_dist
            }) << "\n";
        }
    }
}