#include <bits/stdc++.h>
using namespace std;

struct segtree {

    segtree *left = nullptr, *right = nullptr;
    int mini = 0;

    void pull() {
        mini = min(left->mini, right->mini);
    }

    void push() {
        if (left == nullptr) {
            left = new segtree();
            right = new segtree();
        }
    }

    void update(int a, int x, int l, int r) {
        if (l == r) {
            mini = x;
        } else {
            push();
            int m = (l + r) / 2;
            if (a <= m) {
                left->update(a, x, l, m);
            } else {
                right->update(a, x, m + 1, r);
            }
            pull();
        }
    }

    int query(int a, int b, int l, int r) {
        if (b < l || r < a) {
            return INT_MAX;
        } else if (a <= l && r <= b) {
            return mini;
        } else {
            push();
            int m = (l + r) / 2;
            return min(left->query(a, b, l, m), right->query(a, b, m + 1, r));
        }
    }

};

const int N = 100000 + 1;
const int Q = 200000;

vector<array<int, 4>> areas_x[N], areas_y[N];
vector<int> rooks_x[N], rooks_y[N];
bool ans[Q];

void solve(vector<int> *rooks, vector<array<int, 4>> *areas, int n, int m) {
    segtree *min_tree = new segtree();
    for (int x = 1; x <= n; ++x) {
        for (auto y : rooks[x]) {
            min_tree->update(y, x, 1, m);
        }

        for (auto [l, r, y, i] : areas[x]) {
            ans[i] |= min_tree->query(l, r, 1, m) >= y;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        rooks_x[x].push_back(y);
        rooks_y[y].push_back(x);
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        areas_x[x2].push_back({y1, y2, x1, i});
        areas_y[y2].push_back({x1, x2, y1, i});
    }

    solve(rooks_x, areas_x, n, m);
    solve(rooks_y, areas_y, m, n);

    for (int i = 0; i < q; ++i) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
}