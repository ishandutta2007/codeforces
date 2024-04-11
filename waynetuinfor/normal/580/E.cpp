#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int mod = 479001599;
const int p = 101;
int a[maxn];

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

struct SegmentTree {
#define M ((L + R) >> 1)
    int base, sum, tag;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        lc = rc = nullptr; 
        tag = -1;
        if (L == R) {
            base = fpow(p, L);
            sum = mul(base, a[L]);
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        base = add(lc->base, rc->base);
        sum = add(lc->sum, rc->sum);
    }
    void modify(int L, int R, int l, int r, int x) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            tag = x; sum = mul(base, x);
            return;
        }
        lc->modify(L, M, l, r, x); rc->modify(M + 1, R, l, r, x);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return add(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
    void push() {
        if (tag == -1 || lc == nullptr) return;
        lc->tag = tag; lc->sum = mul(lc->base, tag);
        rc->tag = tag; rc->sum = mul(rc->base, tag);
        tag = -1;
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) a[i] = s[i - 1] - '0';
    st = new SegmentTree(1, n);    
    m += k; while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, c; cin >> l >> r >> c;
            st->modify(1, n, l, r, c);
        } else {
            int l, r, d; cin >> l >> r >> d;
            int ls = st->query(1, n, l + d, r), rs = st->query(1, n, l, r - d);
            ls = mul(ls, fpow(fpow(p, l + d - 1), mod - 2)); rs = mul(rs, fpow(fpow(p, l - 1), mod - 2));
            if (ls == rs) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}