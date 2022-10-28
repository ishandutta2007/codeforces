#include <bits/stdc++.h>
using namespace std;

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    int mini = 0, lazy = 0;

    void apply(int x) {
        mini += x, lazy += x;
    }

    void pull() {
        mini = min(left->mini, right->mini);
    }

    void push() {
        if (!left) {
            left = new segtree();
            right = new segtree();
        }

        if (lazy != 0) {
            left->apply(lazy);
            right->apply(lazy);
            lazy = 0;
        }
    }

    void update(int a, int b, int x, int l, int r) {
        if (b < l || r < a) {
            return;
        } else if (a <= l && r <= b) {
            apply(x);
        } else {
            push();
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m + 1, r);
            pull();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> segments;
    for (int i = 0; i < n; ++i) {
        int l, r, w;
        cin >> l >> r >> w;
        segments.push_back({w, l, r});
    }
    sort(segments.begin(), segments.end());

    int ans = INT_MAX;
    segtree *mini = new segtree();
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && mini->mini == 0) {
            auto [w, l, r] = segments[j++];
            mini->update(l, r - 1, 1, 1, m - 1);
        }

        if (mini->mini > 0) {
            ans = min(ans, segments[j - 1][0] - segments[i][0]);
        }

        auto [w, l, r] = segments[i];
        mini->update(l, r - 1, -1, 1, m - 1);
    }

    cout << ans << "\n";
}