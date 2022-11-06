#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; 
    scanf("%d%d", &n, &q);
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    constexpr int kC = 1'000'000;
    a[0] = kC, a[n + 1] = 0;
    vector<pair<int, int>> tree((kC + 1) * 4);
    vector<int> tag((kC + 1) * 4);

    auto Merge = [&](auto a, auto b) {
        if (a.first < b.first) return a;
        if (b.first < a.first) return b;
        return make_pair(a.first, a.second + b.second);
    };

    auto Build = [&](auto self, int l, int r, int o = 0) {
        if (r - l == 1) {
            tree[o] = make_pair(kC, 1);
            return;
        }
        int m = (l + r) >> 1;
        self(self, l, m, o * 2 + 1);
        self(self, m, r, o * 2 + 2);
        tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    auto Push = [&](int o) {
        for (int v = 1; v <= 2; ++v) {
            tree[o * 2 + v].first += tag[o];
            tag[o * 2 + v] += tag[o];
        }
        tag[o] = 0;
    };

    auto Modify = [&](auto self, int l, int r, int ql, int qr, int v, int o = 0) {
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) {
            tree[o].first += v;
            tag[o] += v;
            return;
        }
        Push(o);
        int m = (l + r) >> 1;
        self(self, l, m, ql, qr, v, o * 2 + 1);
        self(self, m, r, ql, qr, v, o * 2 + 2);
        tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    auto Update = [&](auto self, int l, int r, int p, int v, int o = 0) {
        if (r - l == 1) {
            tree[o].first += v;
            tree[o].second = 1;
            return;
        }
        Push(o);
        int m = (l + r) >> 1;
        if (p < m) self(self, l, m, p, v, o * 2 + 1);
        else self(self, m, r, p, v, o * 2 + 2);
        tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    vector<int> cnt(kC + 1);

    auto Insert = [&](int v) {
        if (cnt[v]++ == 0) Update(Update, 1, kC + 1, v, -kC);
    };

    auto Erase = [&](int v) {
        if (--cnt[v] == 0) Update(Update, 1, kC + 1, v, kC); 
    };

    Build(Build, 1, kC + 1);
    for (int i = 1; i <= n; ++i) Insert(a[i]);

    auto UpdateEdge = [&](int p, int v) {
        int x = min(a[p], a[p - 1]), y = max(a[p], a[p - 1]);
        Modify(Modify, 1, kC + 1, x + 1, y + 1, v);
    };

    for (int i = 1; i <= n + 1; ++i) UpdateEdge(i, 1);
    for (int i = 0; i < q; ++i) {
        int p, v;
        scanf("%d%d", &p, &v);
        UpdateEdge(p, -1);
        UpdateEdge(p + 1, -1);
        Erase(a[p]);
        a[p] = v;
        Insert(a[p]);
        UpdateEdge(p, 1);
        UpdateEdge(p + 1, 1);
        printf("%d\n", tree[0].second);
    }
}