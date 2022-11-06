#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
string v = "aeiouAEIOU";
int a[maxn];

struct segtree {
#define M ((L + R) >> 1)
    segtree *lc, *rc;
    int pos;
    void pull() { pos = min(lc->pos, rc->pos); }
    segtree(int L, int R) {
        lc = rc = nullptr; pos = inf;
        if (L == R) return;
        lc = new segtree(L, M); rc = new segtree(M + 1, R);
        pull();
    }
    void modify(int L, int R, int p, int v) {
        if (L == R) return pos = min(pos, v), void();
        if (p <= M) lc->modify(L, M, p, v);
        else rc->modify(M + 1, R, p, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return inf;
        if (L >= l && R <= r) return pos;
        return min(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        bool vow = false;
        for (int j = 0; j < 10; ++j) if (s[i] == v[j]) vow = true;
        a[i + 1] = (vow ? 1 : 2);
    }
    st = new segtree(0, maxn + maxn);
    int vc = 0, cc = 0;
    int ans = 0, cnt = 0;
    st->modify(0, maxn + maxn, 0 + maxn, 0);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) ++vc; else ++cc;
        int q = st->query(0, maxn + maxn, vc - 2 * cc + maxn, maxn + maxn);
        st->modify(0, maxn + maxn, vc - 2 * cc + maxn, i);
        if (i - q  > ans) ans = i - q, cnt = 1;
        else if (i - q == ans) ++cnt;
    }
    if (ans == 0) cout << "No solution" << endl;
    else cout << ans << ' ' << cnt << endl;
    return 0;
}