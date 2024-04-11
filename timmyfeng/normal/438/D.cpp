#include <bits/stdc++.h>
using namespace std;

struct segtree {
    segtree *left, *right;
    long long sum;
    int maxi;

    segtree(int l, int r, int *a) {
        if (l == r) {
            maxi = sum = a[l];
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m, a);
            right = new segtree(m + 1, r, a);
            pull();
        }
    }

    void pull() {
        sum = left->sum + right->sum;
        maxi = max(left->maxi, right->maxi);
    }

    void update(int a, int b, int x, int l, int r) {
        if (b < l || r < a || maxi < x) {
            return;
        } else if (l == r) {
            maxi %= x;
            sum = maxi;
        } else {
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m + 1, r);
            pull();
        }
    }

    void set(int a, int x, int l, int r) {
        if (l == r) {
            maxi = sum = x;
        } else {
            int m = (l + r) / 2;
            if (a <= m) {
                left->set(a, x, l, m);
            } else {
                right->set(a, x, m + 1, r);
            }
            pull();
        }
    }

    long long query(int a, int b, int l, int r) {
        if (b < l || r < a) {
            return 0;
        } else if (a <= l && r <= b) {
            return sum;
        } else {
            int m = (l + r) / 2;
            return left->query(a, b, l, m) + right->query(a, b, m + 1, r);
        }
    }
};

const int N = 100001;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    segtree *sum = new segtree(1, n, a);

    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << sum->query(l, r, 1, n) << "\n";
        } else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            sum->update(l, r, x, 1, n);
        } else {
            int k, x;
            cin >> k >> x;
            sum->set(k, x, 1, n);
        }
    }
}