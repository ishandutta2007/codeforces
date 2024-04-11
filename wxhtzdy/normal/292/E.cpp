#include <bits/stdc++.h>

using i64 = long long;

struct LazySegmentTree{
    int n;
    std::vector<int> val, lzy;
    LazySegmentTree(int _n) {
        n = _n;
        val.resize(4 * n);
        lzy.resize(4 * n);
        for (int i = 0; i < 4 * n; i++)
            val[i] = -1, lzy[i] = -1;
    }
    void push(int p, int l, int r) {
        if (lzy[p] == -1) return;
        val[p] = lzy[p];
        if (l != r) {
            lzy[p * 2] = lzy[p];
            lzy[p * 2 + 1] = lzy[p];
        }
        lzy[p] = -1;
    }
    void update(int p, int l, int r, int ll, int rr, int x) {
        push(p, l, r);
        if (l > r || l > rr || r < ll) return;
        if (ll <= l && r <= rr) {
            lzy[p] = x;
            push(p, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(p * 2, l, mid, ll, rr, x);
        update(p * 2 + 1, mid + 1, r, ll, rr, x);
    }
    int get(int p, int l, int r, int x) {
        push(p, l, r);
        if (l == r) return val[p];
        int mid = (l + r) / 2;
        if (x <= mid) return get(p * 2, l, mid, x);
        else return get(p * 2 + 1, mid + 1, r, x);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    LazySegmentTree A(n), B(n);

    while (q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;

            x--;
            y--;

            A.update(1, 0, n - 1, y, y + k - 1, x);
            B.update(1, 0, n - 1, y, y + k - 1, y);
        } else {
            int i;
            std::cin >> i;

            i--;

            int x = A.get(1, 0, n - 1, i);
            int y = B.get(1, 0, n - 1, i);

            if (y == -1) std::cout << b[i] << "\n";
            else std::cout << a[x + i - y] << "\n";
        }
    }

    return 0;
}