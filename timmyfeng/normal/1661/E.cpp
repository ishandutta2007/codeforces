#include <bits/stdc++.h>
using namespace std;

string matrix[3];

struct segment {
    array<int, 6> color;
    int components = 0;
};

segment combine(const segment &left, const segment &right) {
    if (left.components == -1) return right;
    if (right.components == -1) return left;

    segment s;

    s.components = left.components + right.components;

    for (int i = 0; i < 3; ++i) {
        s.color[i] = left.color[i];
        s.color[i + 3] = right.color[i + 3];
    }

    array<int, 6> inside_color;
    for (int i = 0; i < 3; ++i) {
        inside_color[i] = left.color[i + 3];
        inside_color[i + 3] = right.color[i];
    }

    for (int i = 0; i < 3; ++i) {
        if (inside_color[i] != -1 && inside_color[i + 3] != -1 && inside_color[i] != inside_color[i + 3]) {
            int temp = inside_color[i + 3];
            for (auto &j : s.color) if (j == temp) j = inside_color[i];
            for (auto &j : inside_color) if (j == temp) j = inside_color[i];
            --s.components;
        }
    }

    return s;
}

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    segment s;

    segtree(int l, int r) {
        if (l + 1 == r) {
            for (int i = 0; i < 3; ++i) {
                if (matrix[i][l] == '0') {
                    s.color[i] = -1;
                } else if (i && matrix[i - 1][l] == '1') {
                    s.color[i] = s.color[i - 1];
                } else {
                    s.color[i] = 3 * l + i;
                    ++s.components;
                }
                s.color[i + 3] = s.color[i];
            }
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m, r);
            s = combine(left->s, right->s);
        }
    }

    segment query(int l, int r, int a, int b) {
        if (a <= l && r <= b) return s;
        if (b <= l || r <= a) return {{}, -1};

        int m = (l + r) / 2;
        return combine(
            left->query(l, m, a, b),
            right->query(m, r, a, b)
        );
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (auto &row : matrix) cin >> row;

    segtree *root = new segtree(0, n);

    int q; cin >> q;

    while (q--) {
        int l, r; cin >> l >> r;
        cout << root->query(0, n, l - 1, r).components << "\n";
    }
}