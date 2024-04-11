#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int a[maxn];

struct Seg {
    Seg *lc, *rc;
    long long Min, tag;
    Seg(int L, int R) {
        lc = rc = nullptr;
        tag = LLONG_MIN;
        if (L == R) { Min = a[L]; return; }
        int M = (L + R) >> 1;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
        pull();
    }
    void pull() {
        Min = min(lc->Min, rc->Min);
    }
    long long query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return LLONG_MAX;
        if (L >= l && R <= r) return Min;
        int M = (L + R) >> 1;
        return min(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
    void push(int L, int R) {
        if (L == R) return;
        if (tag == LLONG_MIN) return;
        if (lc->tag == LLONG_MIN) lc->tag = 0;
        if (rc->tag == LLONG_MIN) rc->tag = 0;
        lc->Min += tag; lc->tag += tag;
        rc->Min += tag; rc->tag += tag;
        tag = LLONG_MIN;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            Min += v;
            if (tag == LLONG_MIN) tag = 0;
            tag += v;
            return;
        }
        int M = (L + R) >> 1;
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    st = new Seg(0, n - 1);
    cin >> m; string _; getline(cin, _); while (m--) {
        int l, r, v;
        string s; getline(cin, s);
        stringstream ss(s);
        vector<int> args;
        int x; while (ss >> x) args.push_back(x);
        if (args.size() == 2) {
            l = args[0], r = args[1];
            if (r >= l) {
                cout << st->query(0, n - 1, l, r) << '\n';
            } else {
                cout << min(st->query(0, n - 1, l, n - 1), st->query(0, n - 1, 0, r)) << '\n';
            }
        } else {
            l = args[0], r = args[1], v = args[2];
            if (r >= l) {
                st->modify(0, n - 1, l, r, v);
            } else {
                st->modify(0, n - 1, l, n - 1, v);
                st->modify(0, n - 1, 0, r, v);
            }
        }
    }
    return 0;
}