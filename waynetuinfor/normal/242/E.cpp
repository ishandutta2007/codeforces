#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

struct Seg {
    Seg *lc, *rc;
    int bit[20], tag;
    long long sum;
#define M ((L + R) >> 1)
    Seg(int L, int R) {
        lc = rc = nullptr; tag = 0;
        sum = 0;
        memset(bit, 0, sizeof(bit));
        if (L == R) {
            for (int i = 0; i < 20; ++i) {
                if ((a[L] >> i) & 1) bit[i] = 1;
                else bit[i] = -1;
            }
            sum = a[L];
            return;
        }
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
        pull();
    }
    void pull() {
        sum = lc->sum + rc->sum;
        for (int i = 0; i < 20; ++i) {
            bit[i] = lc->bit[i] + rc->bit[i];
        }
    }
    void modify(int L, int R, int l, int r, int x) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            for (int i = 0; i < 20; ++i) {
                if ((x >> i) & 1) bit[i] *= -1, sum += (1LL << i) * (long long)bit[i];
            }
            tag ^= x;
            return;
        }
        lc->modify(L, M, l, r, x); rc->modify(M + 1, R, l, r, x);
        pull();
    }
    long long query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
    void push() {
        if (!lc) return;
        if (!tag) return;
        for (int i = 0; i < 20; ++i) {
            if ((tag >> i) & 1) {
                lc->bit[i] *= -1; lc->sum += (1LL << i) * (long long)lc->bit[i];
                rc->bit[i] *= -1; rc->sum += (1LL << i) * (long long)rc->bit[i];
            }
        }
        lc->tag ^= tag; rc->tag ^= tag;
        tag = 0;
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    st = new Seg(0, n - 1);
    int m; cin >> m; while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r; --l, --r;
            cout << st->query(0, n - 1, l, r) << endl;
        } else {
            int l, r, x; cin >> l >> r >> x; --l, --r;
            st->modify(0, n - 1, l, r, x);
        }
    }
    return 0;
}