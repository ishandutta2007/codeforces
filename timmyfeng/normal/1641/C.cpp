#include <bits/stdc++.h>
using namespace std;

struct segtree {
    struct node {
        node *left, *right;
        int min_value;

        node(int l, int r) {
            min_value = INT_MAX;
            if (r - l > 1) {
                int m = (l + r) / 2;
                left = new node(l, m);
                right = new node(m, r);
            }
        }

        int query(int a, int b, int l, int r) {
            if (a <= l && r <= b) return min_value;
            if (b <= l || r <= a) return INT_MAX;

            int m = (l + r) / 2;
            return min(left->query(a, b, l, m), right->query(a, b, m, r));
        }

        void update(int a, int x, int l, int r) {
            if (r - l == 1) {
                min_value = min(min_value, x);
            } else {
                int m = (l + r) / 2;
                if (a < m) left->update(a, x, l, m);
                else right->update(a, x, m, r);
                min_value = min(left->min_value, right->min_value);
            }
        }
    };

    segtree(int n) : n(n) {
        root = new node(1, n + 1);
    }

    int operator()(int a, int b) {
        return root->query(a, b, 1, n + 1);
    }

    void update(int a, int x) {
        root->update(a, x, 1, n + 1);
    }

    node *root;
    int n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    segtree closest(n);

    set<int> patients;
    for (int i = 0; i <= n + 1; ++i) patients.insert(i);

    while (q--) {
        int type; cin >> type;
        if (type == 0) {
            int l, r, x; cin >> l >> r >> x;
            if (x == 0) {
                auto it = patients.lower_bound(l);
                while (it != patients.end() && *it <= r) {
                    patients.erase(it++);
                }
            } else {
                closest.update(l, r);
            }
        } else {
            int j; cin >> j;
            if (patients.contains(j)) {
                auto it = patients.find(j);
                auto prv = it; --prv;
                auto nxt = it; ++nxt;

                if (closest(*prv + 1, j + 1) < *nxt) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
            } else cout << "NO\n";
        }
    }
}