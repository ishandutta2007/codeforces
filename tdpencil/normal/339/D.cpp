#include <bits/stdc++.h>
using namespace std;


// a * b = x * y
// find factors of x * y

struct segtree {
    using ll = long long;
    bool v;
    int leftmost, rightmost;
    struct segtree *lChild, *rChild;
    int val;
    int combine(int x, int y) {
        return (v?x|y:x^y);
    }

    segtree(int l, int r, vector<int> &vals) {
        leftmost = l;
        rightmost = r;
        if(l == r) {
            v = 0;
            val = vals[l];
        } else {
            int mid = (l + r) >> 1;
            lChild = new segtree(l, mid, vals);
            rChild = new segtree(mid + 1, r, vals);
            v = !lChild->v;
            val = combine(lChild->val, rChild->val);
        }
    }

    void upd(int pos, int v) {
        if(leftmost == rightmost){ 
            val = v;
        } else {
            if(lChild->rightmost >= pos)
                lChild->upd(pos, v);
            else
                rChild->upd(pos, v);
            val = combine(lChild->val, rChild->val);
        }
    }


    ll query(int l, int r) {
        if(l > rightmost || r < leftmost)
            return 0;
        else if(l <= leftmost && r >= rightmost)
            return val;
        else
            return lChild->query(l, r) + rChild->query(l, r);
    }

};
void run_case() {
    int n, m; cin >> n >> m;
    n = 1 << n;
    vector<int> a(n);
    for(int &i : a)
        cin >> i;

    segtree st(0, n - 1, a);
    while(m--) {
        int p, b;
        cin >> p >> b;
        --p;
        st.upd(p, b);
        cout << st.query(0, n - 1) << "\n";
    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

#ifdef RUN_CASE
    cin >> T;
#endif

    for(int test_case = 0; test_case < T; test_case++)
        run_case();
}