#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    int sum, v; 
    segtree(int l, int r) {
        lc = rc = nullptr; sum = 0; v = -1;
        if (l == r) return;
        lc = new segtree(l, m); rc = new segtree(m + 1, r);
    }
    void add(int l, int r, int p, int k) {
        if (l == r) return ++sum, v = k, void();
        if (p <= m) lc->add(l, m, p, k);
        else rc->add(m + 1, r, p, k);
        sum = lc->sum + rc->sum;
    }
    void del(int l, int r, int p) {
        if (l == r) return --sum, void();
        if (lc->sum >= p) lc->del(l, m, p);
        else rc->del(m + 1, r, p - lc->sum);
        sum = lc->sum + rc->sum;
    }
    void dfs(int l, int r) {
        if (l == r) {
            if (v != -1 && sum > 0) cout << v;
            return;
        }
        lc->dfs(l, m); rc->dfs(m + 1, r);
    }
#undef m
} *st;

int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    st = new segtree(1, n);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (t == -1) {
            int k = 0;
            for (int j = 1; j <= m; ++j) {
                if (st->sum < a[j] - k) break;
                st->del(1, n, a[j] - k);
                ++k;
            }
            continue;
        } 
        st->add(1, n, ++p, t);
    }
    if (st->sum == 0) return cout << "Poor stack!" << endl, 0;
    st->dfs(1, n); cout << endl;
    return 0;
}