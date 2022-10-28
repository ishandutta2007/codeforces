#include <bits/stdc++.h>
using namespace std;

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    long long min_b, max_b, sum_b, lazy = 0;

    segtree(vector<long long> &b, int l, int r) {
        if (l == r) {
            min_b = max_b = sum_b = b[l];
        } else {
            int m = (l + r) / 2;
            left = new segtree(b, l, m);
            right = new segtree(b, m + 1, r);
            pull();
        }
    }

    void apply(long long x, int l, int r) {
        min_b += x, max_b += x, lazy += x;
        sum_b += x * (r - l + 1);
    }

    void pull() {
        min_b = left->min_b;
        max_b = right->max_b;
        sum_b = left->sum_b + right->sum_b;
    }

    void push(int l, int r) {
        if (lazy != 0) {
            int m = (l + r) / 2;
            left->apply(lazy, l, m);
            right->apply(lazy, m + 1, r);
            lazy = 0;
        }
    }

    void update(int a, int b, long long x, int l, int r) {
        if (b < l || r < a) {
            return;
        } else if (a <= l && r <= b) {
            apply(x, l, r);
        } else {
            push(l, r);
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m + 1, r);
            pull();
        }
    }

    void query(long long x, long long &ans, int l, int r) {
        if (x <= min_b) {
            ans += (r - l + 1) * x;
        } else if (max_b < x) {
            ans += sum_b;
        } else {
            push(l, r);
            int m = (l + r) / 2;
            left->query(x, ans, l, m);
            right->query(x, ans, m + 1, r);
        }
    }
};

vector<long long> read(int n) {
    vector<long long> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    for (int i = n - 1; i > 0; --i) {
        a[i] -= a[i - 1];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> a = read(n), b = read(m);
    a[0] += b[0], b[0] = 0;

    long long sum = 0;
    for (int i = 1; i < m; ++i) {
        sum += b[i] * (m - i);
    }

    segtree* column = new segtree(b, 0, m - 1);

    while (q--) {
        int type, k;
        long long d;
        cin >> type >> k >> d;

        if (type == 1) {
            for (int i = n - k; i < n; ++i) {
                a[i] += d;
            }
        } else {
            if (k == m) {
                a[0] += d;
                k = m - 1;
            }
            column->update(m - k, m - 1, d, 0, m - 1);
            sum += d * k * (k + 1) / 2;
        }

        long long ans = a[0] * (n + m - 1) + sum;
        for (int i = 1; i < n; ++i) {
            column->query(a[i], ans, 0, m - 1);
            ans += (n - i) * a[i];
        }

        cout << ans << "\n";
    }
}