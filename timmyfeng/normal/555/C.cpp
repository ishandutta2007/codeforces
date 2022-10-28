#include <bits/stdc++.h>
using namespace std;

struct segtree {

    segtree *left = nullptr, *right = nullptr;
    set<int> values;

    void push() {
        if (!left) {
            left = new segtree();
            right = new segtree();
        }
    }

    void update(int a, int b, int x, int l, int r) {
        if (b < l || r < a) {
            return;
        } else if (a <= l && r <= b) {
            values.insert(x);
        } else {
            push();
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m + 1, r);
        }
    }

    int query(int a, int x, int l, int r) {
        int y = 0;
        if (left) {
            int m = (l + r) / 2;
            if (a <= m) {
                y = left->query(a, x, l, m);
            } else {
                y = right->query(a, x, m + 1, r);
            }
        }

        auto it = values.upper_bound(x);
        if (it != values.begin()) {
            y = max(y, *(--it));
        }

        return y;
    }

};

const int N = 200000 + 1;

tuple<int, int, char> queries[N];

void unique(vector<int> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int get(int x, vector<int> &v) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> u, v;

    for (int i = 1; i <= q; ++i) {
        char d;
        int x, y;
        cin >> x >> y >> d;
        u.push_back(x);
        v.push_back(y);
        queries[i] = {x, y, d};
    }

    unique(u), unique(v);

    segtree *horizontal = new segtree(), *vertical = new segtree();
    map<int, map<int, int>> row, column;

    for (int i = 1; i <= q; ++i) {
        auto [x, y, d] = queries[i];
        if (d == 'U') {
            int eaten = 0;

            map<int, int> &c = column[x];
            auto it = c.upper_bound(y);
            if (it != c.begin()) {
                eaten = min(y, (--it)->second);
            }

            eaten = max(eaten, horizontal->query(get(x, u), y, 1, u.size()));

            cout << y - eaten << "\n";

            if (y > eaten) {
                c[eaten + 1] = y;
                vertical->update(
                    get(eaten + 1, v), get(y, v), x, 1, v.size()
                );
            }
        } else {
            int eaten = 0;

            map<int, int> &r = row[y];
            auto it = r.upper_bound(x);
            if (it != r.begin()) {
                eaten = min(x, (--it)->second);
            }

            eaten = max(eaten, vertical->query(get(y, v), x, 1, v.size()));

            cout << x - eaten << "\n";

            if (x > eaten) {
                r[eaten + 1] = x;
                horizontal->update(
                    get(eaten + 1, u), get(x, u), y, 1, u.size()
                );
            }
        }
    }
}