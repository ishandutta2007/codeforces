#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

struct subarray {
    long long ways, left, right, len;
};

int arr[N];

subarray combine(subarray l, subarray r, int index) {
    if (arr[index] > arr[index + 1]) {
        return {
            l.ways + r.ways,
            l.left,
            r.right,
            l.len + r.len
        };
    } else {
        return {
            l.ways + r.ways + l.right * r.left,
            l.left == l.len ? l.left + r.left : l.left,
            r.right == r.len ? r.right + l.right : r.right,
            l.len + r.len
        };
    }
}

struct segtree {

    segtree *left, *right;
    subarray value;

    segtree(int l, int r) {
        if (l == r) {
            value = {1, 1, 1, 1};
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m + 1, r);
            value = combine(left->value, right->value, m);
        }
    }

    void update(int a, int l, int r) {
        if (l == r) {
            return;
        } else {
            int m = (l + r) / 2;
            if (a <= m) {
                left->update(a, l, m);
            } else {
                right->update(a, m + 1, r);
            }
            value = combine(left->value, right->value, m);
        }
    }

    subarray query(int a, int b, int l, int r) {
        if (a == l && r == b) {
            return value;
        } else {
            int m = (l + r) / 2;
            if (a <= m && m < b) {
                return combine(left->query(a, m, l, m), right->query(m + 1, b, m + 1, r), m);
            } else if (a <= m) {
                return left->query(a, b, l, m);
            } else {
                return right->query(a, b, m + 1, r);
            }
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    segtree *alice = new segtree(1, n);

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            arr[a] = b;
            alice->update(a, 1, n);
        } else {
            cout << alice->query(a, b, 1, n).ways << "\n";
        }
    }
}