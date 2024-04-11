#include <bits/stdc++.h>
using namespace std;

// define a segment tree S where for each node of S, (l, r), we maintain
// the costs to ensure that the given range does not contain:
//  1) a
//  2) b
//  3) c
//  4) ab
//  5) bc
//  6) abc

// cost(ab) = min(
//      left.cost(a) + right.cost(ab)
//      left.cost(ab) + right.cost(b)
// )

// cost(abc) = min(
//      left.cost(a) + right.cost(abc)
//      left.cost(ab) + right.cost(bc)
//      left.cost(abc) + right.cost(c)
// )

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    int a, b, c, ab, bc, abc;

    segtree(int l, int r, string &s) {
        if (l == r) {
            apply(s[l]);
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m, s);
            right = new segtree(m + 1, r, s);
            pull();
        }
    }

    void apply(char x) {
        ab = bc = abc = 0;
        a = (x == 'a');
        b = (x == 'b');
        c = (x == 'c');
    }

    void pull() {
        a = left->a + right->a;
        b = left->b + right->b;
        c = left->c + right->c;

        ab = min(left->a + right->ab, left->ab + right->b);
        bc = min(left->b + right->bc, left->bc + right->c);

        abc = min({left->a + right->abc, left->ab + right->bc, left->abc + right->c});
    }

    void update(int a, int x, int l, int r) {
        if (l == r) {
            apply(x);
        } else {
            int m = (l + r) / 2;
            if (a <= m) {
                left->update(a, x, l, m);
            } else {
                right->update(a, x, m + 1, r);
            }
            pull();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    segtree *str = new segtree(0, n - 1, s);

    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;

        str->update(pos - 1, c, 0, n - 1);

        cout << str->abc << "\n";
    }
}