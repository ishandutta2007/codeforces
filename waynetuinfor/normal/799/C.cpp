#include <bits/stdc++.h>
using namespace std;

struct Seg {
    Seg *lc, *rc;
    set<pair<int, int>, greater<pair<int, int>>> s;
    pair<int, int> a, b;
    Seg(int L=1, int R=(int)1e5) {
        lc = rc = nullptr;
        a = b = make_pair(-1, -1);
        if (L == R) return;
        int M = (L + R) >> 1;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    void pull() {
        vector<pair<int, int>> tmp; tmp.push_back(lc->a); tmp.push_back(lc->b);
        tmp.push_back(rc->a); tmp.push_back(rc->b);
        sort(tmp.begin(), tmp.end());
        a = tmp[tmp.size() - 1]; b = tmp[tmp.size() - 2];
    }
    int query(int L, int R, int l, int r, int id) {
        if (L > r || l > R) return -1;
        if (L >= l && R <= r) {
            if (a.second == id) return b.first;
            return a.first; 
        }
        int M = (L + R) >> 1;
        return max(lc->query(L, M, l, r, id), rc->query(M + 1, R, l, r, id));
    }
    void modify(int L, int R, int p, int v, int id) {
        if (L == R) {
            pair<int, int> tmp = make_pair(v, id);
            if (tmp > a) a = tmp;
            else if (tmp > b) b = tmp;
            return;
        }
        int M = (L + R) >> 1;
        if (p <= M) lc->modify(L, M, p, v, id);
        else rc->modify(M + 1, R, p, v, id);
        pull();
    }
} *st1, *st2;

struct F { int b, p, id; char ch; };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, d; cin >> n >> c >> d;
    st1 = new Seg(1, (int)1e5); st2 = new Seg(1, (int)1e5);
    vector<F> fs; int ind = 0;
    for (int i = 0; i < n; ++i) {
        int b, p; char ch; cin >> b >> p >> ch;
        if (ch == 'C') {
            if (p > c) continue;
            st1->modify(1, (int)1e5, p, b, ++ind);
        } else {
            if (p > d) continue;
            st2->modify(1, (int)1e5, p, b, ++ind);
        }
        fs.push_back((F){ b, p, ind, ch });
    }
    int ans = 0;
    for (F f : fs) {
        if (f.ch == 'C') {
            int q = st1->query(1, (int)1e5, 1, c - f.p, f.id);
            if (q != -1) ans = max(ans, f.b + q);
            q = st2->query(1, (int)1e5, 1, d, f.id);
            if (q != -1) ans = max(ans, f.b + q);
        } else {
            int q = st2->query(1, (int)1e5, 1, d - f.p, f.id);
            if (q != -1) ans = max(ans, f.b + q);
            q = st1->query(1, (int)1e5, 1, c, f.id);
            if (q != -1) ans = max(ans, f.b + q);
        }
    }
    cout << ans << '\n';
    return 0;
}