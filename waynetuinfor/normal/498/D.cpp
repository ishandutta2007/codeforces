#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

struct segtree {
#define M ((L + R) >> 1)
    segtree *lc, *rc;
    int dp[60];
    segtree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) {
            for (int i = 0; i < 60; ++i) {
                dp[i] = 1;
                if (i % a[L] == 0) ++dp[i]; 
            }
            return;
        }
        lc = new segtree(L, M); rc = new segtree(M + 1, R);
        pull();
    }
    void pull() {
        for (int i = 0; i < 60; ++i) {
            int to = (i + lc->dp[i]) % 60;
            dp[i] = lc->dp[i] + rc->dp[to];
        }
    }
    void modify(int L, int R, int p, int v) {
        if (L == R) {
            for (int i = 0; i < 60; ++i) {
                dp[i] = 1;
                if (i % v == 0) ++dp[i];
            }
            return;
        }
        if (p <= M) lc->modify(L, M, p, v);
        else rc->modify(M + 1, R, p, v);
        pull();
    }
    int query(int L, int R, int l, int r, int idx) {
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return dp[idx];
        int tl = lc->query(L, M, l, r, idx);
        int to = (idx + tl) % 60;
        return tl + rc->query(M + 1, R, l, r, to);
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new segtree(1, n);
    int q; cin >> q; while (q--) {
        char c; int x, y; cin >> c >> x >> y;
        if (c == 'A') cout << st->query(1, n, x, y - 1, 0) << endl;
        else st->modify(1, n, x, y);
    }
    return 0;
}