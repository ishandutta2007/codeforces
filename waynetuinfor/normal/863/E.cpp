#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9;
int l[maxn], r[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int val, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = 0; tag = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        val = min(lc->val, rc->val);
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val += v;
            tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return inf;
        if (L >= l && R <= r) return val;
        return min(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
    void push(int L, int R) {
        if (L == R || tag == 0) return;
        lc->val += tag; lc->tag += tag;
        rc->val += tag; rc->tag += tag;
        tag = 0;
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i], vec.push_back(l[i]), vec.push_back(r[i]), vec.push_back(l[i] + 1), vec.push_back(l[i] - 1), vec.push_back(r[i] + 1), vec.push_back(r[i] - 1);
    sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    st = new SegmentTree(1, vec.size());
    for (int i = 0; i < n; ++i) {
        l[i] = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin() + 1;
        r[i] = lower_bound(vec.begin(), vec.end(), r[i]) - vec.begin() + 1;
        st->modify(1, vec.size(), l[i], r[i], 1);
    }
    for (int i = 0; i < n; ++i) {
        int sum = st->query(1, vec.size(), l[i], r[i]);
        if (sum > 1) return cout << i + 1 << endl, 0;
    }
    cout << "-1" << endl;
    return 0;
}