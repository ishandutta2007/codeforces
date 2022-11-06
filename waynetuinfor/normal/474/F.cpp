#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, t, s[maxn];

struct Seg {
    Seg *lc, *rc;
    int cnt, Min, gcd;
    Seg(int L, int R) {
        if (L == R) {
            cnt = 1, Min = s[L], gcd = s[L];
            return;
        }
        int M = (L + R) >> 1;
        lc = new Seg(L, M), rc = new Seg(M + 1, R);
        pull();
    }
    ~Seg() {
        if (lc) delete lc, lc = NULL;
        if (rc) delete rc, rc = NULL;
    }
    void pull() {
        gcd = __gcd(lc->gcd, rc->gcd);
        Min = min(lc->Min, rc->Min);
        cnt = 0;
        if (Min == lc->Min) cnt += lc->cnt;
        if (Min == rc->Min) cnt += rc->cnt;
    }
    tuple<int, int, int> query(int L, int R, int l, int r) {
        if (L > r || l > R) return make_tuple(0, INT_MAX, 0);
        if (L >= l && R <= r) return make_tuple(cnt, Min, gcd);
        int M = (L + R) >> 1;
        tuple<int, int, int> t1 = lc->query(L, M, l, r);
        tuple<int, int, int> t2 = rc->query(M + 1, R, l, r);
        int gcd = __gcd(get<2>(t1), get<2>(t2)), Min = min(get<1>(t1), get<1>(t2));
        if (gcd != Min) return make_tuple(0, Min, gcd);
        int cnt = 0;
        if (get<1>(t1) == Min) cnt += get<0>(t1);
        if (get<1>(t2) == Min) cnt += get<0>(t2);
        return make_tuple(cnt, Min, gcd);
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    st = new Seg(1, n);
    cin >> t; while (t--) {
        int l, r; cin >> l >> r;
        cout << r - l + 1 - get<0>(st->query(1, n, l, r)) << '\n';
    }
    return 0;
}