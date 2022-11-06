#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], d[maxn], md[maxn];
bool v[maxn];
vector<int> pr;

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), md[i] = i;
        for (size_t j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            md[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

void init() {
    sieve();
    for (int i = 1; i < maxn; ++i) {
        d[i] = 1;
        int now = i;
        while (now > 1) {
            int c = 0, dv = md[now];
            while (now % dv == 0) now /= dv, ++c;
            d[i] *= c + 1;
        }
    }
}

struct segtree {
#define m ((l + r) >> 1)
    long long sum;
    bool eng;
    segtree *lc, *rc;
    segtree(int l, int r) {
        if (l == r) lc = rc = nullptr, sum = a[l], eng = a[l] > 2;
        else lc = new segtree(l, m), rc = new segtree(m + 1, r), pull();
    }
    void pull() { sum = lc->sum + rc->sum; eng = lc->eng || rc->eng; }
    long long query(int l, int r, int ql, int qr) {
        if (l > qr || ql > r) return 0;
        if (l >= ql && r <= qr) return sum;
        return lc->query(l, m, ql, qr) + rc->query(m + 1, r, ql, qr);
    }
    void modify(int l, int r, int ql, int qr) {
        if (l > qr || ql > r) return;
        if (l == r) {
            sum = d[sum];
            eng = sum > 2;
            return;
        }
        if (lc->eng) lc->modify(l, m, ql, qr);
        if (rc->eng) rc->modify(m + 1, r, ql, qr);
        pull();
    }
    void dfs(int l, int r) {
        if (l == r) return cout << sum << ' ', void();
        lc->dfs(l, m); rc->dfs(m + 1, r);
    }
#undef m
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new segtree(1, n);
    while (m--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) st->modify(1, n, l, r);
        else cout << st->query(1, n, l, r) << endl;
    }
    return 0;
}