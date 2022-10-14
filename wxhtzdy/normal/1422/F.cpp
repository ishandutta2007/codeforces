#include <bits/stdc++.h>

using i64 = long long;

const int md = 1e9 + 7;

i64 add(i64 a, i64 b) { a += b; return a >= md ? a - md : a; }
i64 mul(i64 a, i64 b) { return a * b % md; }

i64 power(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 res = power(a, b >> 1);
    res = mul(res, res);
    if (b & 1) res = mul(res, a);
    return res;
}

struct SegmentTree {
    std::vector<int> st;
    int n;
    SegmentTree() {}
    void build(int _n) {
        n = _n; st.resize(2 * n + 5);
    }
    void update(int x, int y) {
        x += n;
        st[x] = y;
        for (x >>= 1; x; x >>= 1) {
            st[x] = std::max(st[x * 2], st[x * 2 + 1]);
        }
    }
    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l % 2 == 1) res = std::max(res, st[l++]);
            if (r % 2 == 0) res = std::max(res, st[r--]);
        }
        return res;
    }
};

const int N = 1e5 + 5;
const int M = 40 * N;

int root[N], ls[M], rs[M], tsz;
i64 st[M];

void update(int p, int& c, int l, int r, int x, int y) {
    c = ++tsz; ls[c] = ls[p]; rs[c] = rs[p];
    if (l == r) { st[c] = y; return; }
    int mid = l + r >> 1;
    if (x <= mid) update(ls[p], ls[c], l, mid, x, y);
    else update(rs[p], rs[c], mid + 1, r, x, y);
    st[c] = mul(st[ls[c]], st[rs[c]]);
}

int get(int c, int l, int r, int ql, int qr) {
    if (l > r || l > qr || r < ql) return 1;
    if (ql <= l && r <= qr) return st[c];
    int mid = l + r >> 1;
    return mul(get(ls[c], l, mid, ql, qr), get(rs[c], mid + 1, r, ql, qr));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int MX = sqrt(200005);

    std::vector<bool> prime(MX, true);
    std::vector<int> p;
    for (int i = 2; i < MX; i++) {
        if (!prime[i]) continue;

        p.push_back(i);
        for (int j = i + i; j < MX; j += i) {
            prime[j] = false;
        }
    }

    int n;
    std::cin >> n;

    std::vector<SegmentTree> segtree(p.size());
    for (int i = 0; i < p.size(); i++) {
        segtree[i].build(n);
    }

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];

        for (int j = 0; j < p.size(); j++) {
            int cnt = 0;

            while (a[i] % p[j] == 0) {
                a[i] /= p[j];
                cnt++;
            }

            segtree[j].update(i, cnt);
        }
    }

    std::map<int, int> pos;
    st[0] = 1;
    for (int i = 0; i < n; i++) {
        if (i) root[i] = root[i - 1];
        update(root[i], root[i], 0, n - 1, i, a[i]);
        if (pos.count(a[i])) {
            update(root[i], root[i], 0, n - 1, pos[a[i]], 1);
        }
        pos[a[i]] = i;
    }

    int q;
    std::cin >> q;

    int last = 0;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l = (last + l) % n;
        r = (last + r) % n;

        if (l > r) std::swap(l, r);

        i64 ans = 1;
        for (int i = 0; i < p.size(); i++) {
            ans = mul(ans, power(p[i], segtree[i].get(l, r)));
        }

        ans = mul(ans, get(root[r], 0, n - 1, l, r));

        last = ans;
        std::cout << last << "\n";
    }

    return 0;
}