#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int maxn = 1e5 + 10;

struct Query {
    int t;
    long long l, r;
} qry[maxn];

struct Seg {
    Seg *lc, *rc;
    int sum, tag;
#define M ((L + R) >> 1)
    Seg(int L, int R) {
        lc = rc = nullptr; sum = 0; tag = 0;
        if (L == R) return;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    int query(int L, int R) {
        push(L, R);
        if (L == R) return L;
        if (lc->sum == M - L + 1) return rc->query(M + 1, R);
        return lc->query(L, M);
    }
    void add(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum = R - L + 1, tag = 1;
            return;
        }
        lc->add(L, M, l, r); rc->add(M + 1, R, l, r);
        pull();
    }
    void rem(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum = 0; tag = 2;
            return;
        }
        lc->rem(L, M, l, r); rc->rem(M + 1, R, l, r);
        pull();
    }
    void flp(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum = R - L + 1 - sum; tag = 3 - tag;
            return;
        }
        lc->flp(L, M, l, r); rc->flp(M + 1, R, l, r);
        pull();
    }
    void push(int L, int R) {
        if (!lc || tag == 0) return;
        if (tag == 2) {
            lc->sum = 0; lc->tag = 2;
            rc->sum = 0; rc->tag = 2;
        } else if (tag == 1) {
            lc->sum = M - L + 1; lc->tag = 1;
            rc->sum = R - M; rc->tag = 1;
        } else {
            lc->sum = M - L + 1 - lc->sum; lc->tag = 3 - lc->tag;
            rc->sum = R - M - rc->sum; rc->tag = 3 - rc->tag;
        }
        tag = 0;
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<long long> v; v.push_back(1LL);
    for (int i = 0; i < n; ++i) {
        cin >> qry[i].t >> qry[i].l >> qry[i].r;
        v.push_back(qry[i].l); v.push_back(qry[i].r); v.push_back(qry[i].r + 1);
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    st = new Seg(0, v.size() - 1);
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(v.begin(), v.end(), qry[i].l) - v.begin(), r = lower_bound(v.begin(), v.end(), qry[i].r) - v.begin();
        if (qry[i].t == 1) st->add(0, v.size() - 1, l, r);
        if (qry[i].t == 2) st->rem(0, v.size() - 1, l, r);
        if (qry[i].t == 3) st->flp(0, v.size() - 1, l, r);
        cout << v[st->query(0, v.size() - 1)] << endl;
    }
    return 0;
}