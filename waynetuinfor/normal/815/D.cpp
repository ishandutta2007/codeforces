#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    long long sum;
    int maxv, minv, tag; 
    segtree(int l, int r) {
        sum = maxv = tag = minv = 0;
        if (l == r) lc = rc = nullptr;
        else lc = new segtree(l, m), rc = new segtree(m + 1, r);
    }
    long long query(int l, int r, int ql, int qr) {
        push(l, r);
        if (l > qr || ql > r) return 0;
        if (l >= ql && r <= qr) return sum;
        return lc->query(l, m, ql, qr) + rc->query(m + 1, r, ql, qr);
    }
    void modify(int l, int r, int ql, int qr, int v) {
        push(l, r);
        if (l > qr || ql > r) return;
        if (minv >= v) return;
        if (l >= ql && r <= qr && maxv < v) {
            sum = (r - l + 1) * 1ll * v;
            maxv = minv = v;
            tag = v;
            return;
        }
        lc->modify(l, m, ql, qr, v); rc->modify(m + 1, r, ql, qr, v);
        pull();
    }
    void pull() {
        maxv = max(lc->maxv, rc->maxv);
        minv = min(lc->minv, rc->minv);
        sum = lc->sum + rc->sum;
    }
    void push(int l, int r) {
        if (l == r || tag == 0) return;
        lc->maxv = lc->minv = lc->tag = tag, lc->sum = (m - l + 1) * 1ll * tag;
        rc->maxv = rc->minv = rc->tag = tag, rc->sum = (r - m + 0) * 1ll * tag;
        tag = 0;
    }
#undef m
} *sgt;

vector<pair<int, int>> query[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, p, q, r; cin >> n >> p >> q >> r;
    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        query[p].emplace_back(b, c);
        query[a].emplace_back(b, r);
        query[a].emplace_back(q, c);
    }
    sgt = new segtree(1, q);
    long long ans = 0;
    for (int i = p; i > 0; --i) {
        for (size_t j = 0; j < query[i].size(); ++j) {
            int rgt, val; tie(rgt, val) = query[i][j];
            // cout << "rgt = " << rgt << " val = " << val << endl;
            sgt->modify(1, q, 1, rgt, val);
        }
        // cout << "i = " << i << ": " << sgt->query(1, q, 1, q) << endl;
        ans -= sgt->query(1, q, 1, q);
    }
    ans += p * 1ll * q * r;
    cout << ans << endl;
    return 0;
}