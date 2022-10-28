#include <bits/stdc++.h>
using namespace std;

struct segtree {
    segtree *left, *right;
    int value;

    segtree(int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m + 1, r);
        }
    }

    void update(int a, int x, int l, int r) {
        if (l == r) value = x;
        else {
            int m = (l + r) / 2;
            if (a <= m) left->update(a, x, l, m);
            else right->update(a, x, m + 1, r);
            value = min(left->value, right->value);
        }
    }

    int query(int a, int b, int l, int r) {
        if (a <= l && r <= b) return value;
        else if (a > b || b < l || r < a) return INT_MAX;
        else {
            int m = (l + r) / 2;
            return min(
                left->query(a, b, l, m),
                right->query(a, b, m + 1, r)
            );
        }
    }
};

const int N = 4e5 + 1;
 
vector<array<int, 5>> queries[4][N];
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q; cin >> q;
    vector<int> answer(q, INT_MAX);
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; --r1, --r2;
        if (r1 <= r2) queries[0][r2].push_back({r1, c1, c2, 0, i});
        if (r2 <= r1) queries[1][n - 1 - r2].push_back({n - 1 - r1, c1, c2, 0, i});
    }

    segtree *range_min = new segtree(0, n - 1);

    for (int z = 0; z < 4; ++z) {
        vector<int> hull_r, hull_c;
        for (int r2 = 0; r2 < n; ++r2) {
            while (!hull_c.empty() && hull_c.back() >= a[r2]) {
                hull_c.pop_back(), hull_r.pop_back();
            }
            range_min->update(hull_r.size(), a[r2] - 2 * r2, 0, n - 1);
            hull_c.push_back(a[r2]), hull_r.push_back(r2);

            for (auto [r1, c1, c2, offset, i] : queries[z][r2]) {
                int r_nxt = lower_bound(hull_r.begin(), hull_r.end(), r1) - hull_r.begin();
                int r_wall = lower_bound(hull_c.begin(), hull_c.end(), c2) - hull_c.begin() - 1;
                
                answer[i] = min({answer[i],
                        r2 - r1 + abs(c2 - min(hull_c[r_nxt], c1)) + offset,
                        r2 - r1 + abs(c2 - hull_c[r_nxt]) + 1 + offset,
                        r2 - r1 + c2 + 1 + offset
                });

                if (r_nxt <= r_wall) {
                    answer[i] = min(answer[i], r2 - r1 + min(abs(c2 - hull_c[r_wall]), abs(c2 - hull_c[r_wall + 1])) + 1 + offset);
                } else {
                    int opt_turnpoint = range_min->query(r_wall + 1, r_nxt - 1, 0, n - 1);
                    if (opt_turnpoint < INT_MAX) answer[i] = min(answer[i], r1 + r2 + opt_turnpoint - c2 + (c1 < c2) + offset);
                    if (r_wall >= 0) answer[i] = min(answer[i], r1 + r2 - 2 * hull_r[r_wall] + c2 - hull_c[r_wall] + (c1 < c2) + offset);
                }

                if (z < 2) queries[3 - z][n - 1 - r2].push_back({n - 1 - r2, min(hull_c[r_nxt], c1), c2, r2 - r1, i});
            }
        }

        reverse(a, a + n);
    }

    for (auto i : answer) cout << i << "\n";
}