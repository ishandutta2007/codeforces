#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];
vector<int> primes;
const int sq = 1e3;

struct seg_tree {
    vector<int> seg;
    int sz;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        seg.resize(2 * sz);
    }
    void upd(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = __gcd(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void upd(int i, int v) { upd(i, v, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return 0;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return __gcd(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
} in;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        in.init(n);
        for(int i = 0; i < n; i++)
            in.upd(i, a[i]);
        int lo = 0, hi = n;
        for(int j = 0; j < 20; j++) {
            int mid = (lo + hi) / 2;
            //find if mid steps
            //find gcd of each subarray of len mid
            int eq = in.query(0, mid + 1);
            bool work = true;
            for(int j = 0; j < n; j++) {
                //[j...j+mid+1)
                int cmp;
                if(j + mid + 1 > n) {
                    cmp = __gcd(in.query(j, n), in.query(0, j + mid + 1 - n));
                }
                else {
                    cmp = in.query(j, j + mid + 1);
                }
                if(cmp != eq) work = false;
            }
            if(work) hi = mid;
            else lo=  mid + 1;
        }
        cout << lo << "\n";
    }
}