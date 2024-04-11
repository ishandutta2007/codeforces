#include <bits/stdc++.h>
using namespace std;

struct segtree {
    segtree *left = nullptr, *right = nullptr;
    long long maxi = 0, lazy = 0;

    void apply(long long x) {
        maxi += x, lazy += x;
    }

    void pull() {
        maxi = max(left->maxi, right->maxi);
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

    void update(int a, int b, long long x, int l, int r) {
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

    long long query(int a, int b, int l, int r) {
        if (b < l || r < a) {
            return LLONG_MIN;
        } else if (a <= l && r <= b) {
            return maxi;
        } else {
            push();
            int m = (l + r) / 2;
            return max(left->query(a, b, l, m), right->query(a, b, m + 1, r));
        }
    }
};

const int N = 300000;

long long beauty[N];
int height[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> beauty[i];
    }

    segtree *points = new segtree();
    vector<int> stk = {-1};

    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && height[stk.back()] > height[i]) {
            int j = stk.back();
            stk.pop_back();
            points->update(stk.back() + 1, j, -beauty[j], 0, n);
        }

        points->update(stk.back() + 1, i, beauty[i], 0, n);
        stk.push_back(i);

        points->update(i + 1, i + 1, points->query(0, i, 0, n), 0, n);

    }

    cout << points->query(n, n, 0, n) << "\n";
}