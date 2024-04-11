#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int inf = 2e9 + 100;

namespace sgt {
    array<pair<int, int>, 10> st[maxn * 4];

    void init() {
        for (int i = 0; i < maxn * 4; ++i) {
            for (int j = 0; j < 10; ++j)
                st[i][j] = make_pair(inf, inf);
        }
    }

    void update(array<pair<int, int>, 10> &v, array<pair<int, int>, 10> &w) {
        for (int i = 0; i < 10; ++i) {
            if (w[i].first < v[i].first) {
                v[i].second = v[i].first;
                v[i].first = w[i].first;
            } else if (w[i].first < v[i].second) {
                v[i].second = w[i].first;
            }
            if (w[i].second < v[i].first) {
                v[i].second = v[i].first;
                v[i].first = w[i].second;
            } else if (w[i].second < v[i].second) {
                v[i].second = w[i].second;
            }
        }
    }

    void pull(int o) {
        st[o] = st[o * 2 + 1];
        update(st[o], st[o * 2 + 2]);
    }

    void modify(int l, int r, int p, int v, int o = 0) {
        if (r - l == 1) {
            int z = v;
            for (int i = 0; i < 10; ++i) {
                st[o][i] = make_pair(inf, inf);
                if (v % 10 != 0) st[o][i].first = z;
                v /= 10;
            }
            return;
        }
        if (p < (l + r) >> 1) modify(l, (l + r) >> 1, p, v, o * 2 + 1);
        else modify((l + r) >> 1, r, p, v, o * 2 + 2);
        pull(o);
    }

    array<pair<int, int>, 10> query(int l, int r, int ql, int qr, int o = 0) {
        if (l >= ql && r <= qr) return st[o];
        int m = (l + r) >> 1;
        if (qr <= m) return query(l, m, ql, qr, o * 2 + 1);
        if (ql >= m) return query(m, r, ql, qr, o * 2 + 2);
        array<pair<int, int>, 10> x = query(l, m, ql, qr, o * 2 + 1);
        array<pair<int, int>, 10> y = query(m, r, ql, qr, o * 2 + 2);
        update(x, y);
        return x;
    }
}

int a[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    sgt::init();
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sgt::modify(0, n, i, a[i]);
    }

    while (m--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int i, x; scanf("%d%d", &i, &x);
            sgt::modify(0, n, i - 1, x);
        } else {
            int l, r; scanf("%d%d", &l, &r); --l;
            auto res = sgt::query(0, n, l, r);
            int ans = 2e9 + 10;
            for (int i = 0; i < 10; ++i) {
                long long sum = 1LL * res[i].first + res[i].second;
                if (sum < ans) ans = sum;
            }
            if (ans > 2e9 + 5) ans = -1;
            printf("%d\n", ans);
        }
    }
}