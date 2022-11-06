#include <bits/stdc++.h>
using namespace std;

const int maxn = 35000 + 10, maxk = 50 + 10;
int dp[maxk][maxn], a[maxn], pos[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int val, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        tag = val = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    ~SegmentTree() {
        if (lc) delete lc;
        if (rc) delete rc;
    }
    void pull() {
        val = max(lc->val, rc->val);
    }
    void push() {
        if (!lc || tag == 0) return;
        lc->val += tag; lc->tag += tag;
        rc->val += tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        if (l > r) return;
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val += v; tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return val;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i) {
        st = new SegmentTree(0, n);
        memset(pos, 0, sizeof(pos));
        for (int j = 1; j <= n; ++j) {
            if (!pos[a[j]]) {
                st->modify(0, n, 0, j, 1);
                pos[a[j]] = j;
            } else {
                st->modify(0, n, pos[a[j]] + 1, j, 1);
                pos[a[j]] = j;
            }
            dp[i][j] = st->query(0, n, 0, j);
            st->modify(0, n, j + 1, j + 1, dp[i - 1][j]);
        }
        delete st;
    }    
    cout << dp[k][n] << endl;
    return 0;
}