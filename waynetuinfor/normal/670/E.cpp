#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, inf = 1e9 + 1;
int pr[maxn];
string s;

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int lm, rm;
    bool tag = false;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        lm = inf;
        if (L == R) {
            lm = L; rm = L;
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        lm = min(lc->lm, rc->lm);
        rm = max(lc->rm, rc->rm);
    }
    void set(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            lm = inf; rm = -inf;
            tag = true;
            return;
        }
        lc->set(L, M, l, r); rc->set(M + 1, R, l, r);
        pull();
    }
    void push() {
        if (!lc || !tag) return;
        lc->lm = inf; lc->rm = -inf; lc->tag = true;
        rc->lm = inf; rc->rm = -inf; rc->tag = true;
        tag = false;
    }
    int queryl(int L, int R, int l, int r) {
        if (l > r) return inf;
        push();
        if (L > r || l > R) return inf;
        if (L >= l && R <= r) return lm;
        return min(lc->queryl(L, M, l, r), rc->queryl(M + 1, R, l, r));
    }
    int queryr(int L, int R, int l, int r) {
        if (l > r) return -inf;
        push();
        if (L > r || l > R) return -inf;
        if (L >= l && R <= r) return rm;
        return max(lc->queryr(L, M, l, r), rc->queryr(M + 1, R, l, r));
    }
    void print(int L, int R) {
        push();
        if (L == R) {
            if (lm < inf && rm > -inf) cout << s[L];
            return;
        }
        lc->print(L, M); rc->print(M + 1, R);
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, p; cin >> n >> m >> p; --p;
    cin >> s;
    stack<int> sta;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') sta.push(i);
        else pr[sta.top()] = i, pr[i] = sta.top(), sta.pop();
    }
    st = new SegmentTree(0, n - 1);
    while (m--) {
        char c; cin >> c;
        if (c == 'L') {
            int pos = st->queryr(0, n - 1, 0, p - 1);
            if (pos == -inf) pos = st->queryr(0, n - 1, p + 1, n - 1);
            p = pos;
        }
        if (c == 'R') {
            int pos = st->queryl(0, n - 1, p + 1, n - 1);
            if (pos == inf) pos = st->queryl(0, n - 1, 0, p - 1);
            p = pos;
        }
        if (c == 'D') {
            st->set(0, n - 1, min(p, pr[p]), max(p, pr[p]));
            int pos = st->queryl(0, n - 1, p + 1, n - 1);
            if (pos == inf) pos = st->queryr(0, n - 1, 0, p - 1);
            p = pos;
        }
    }
    st->print(0, n - 1); cout << endl;
    return 0;
}