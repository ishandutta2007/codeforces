#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
long long fac[400001];
long long ifac[400001];
long long MOD = 998244353;

long long inv(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x *= b;
    return x % MOD;
}

long long ch(int n, int k) {
    if (k > n) return 0LL;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

struct seg_tree {
    vector<int> seg;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
    }
    void upd(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void upd(int i, int v) { upd(i, v, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
};

int main() {
    int t; cin >> t;
    fac[0] = 1LL;
    for (int i = 1; i <= 400000; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[400000] = inv(fac[400000]);
    for (int i = 399999; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
    seg_tree sto;
    sto.init(200001);
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> x(m), y(m);
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i];
        }
        vector<int> pos(m);
        for (int i = m - 1; i >= 0; i--) {
            if (sto.query(0, y[i] + 1) == 0) {
                pos[i] = y[i];
                sto.upd(pos[i], 1);
                continue;
            }
            int lo = y[i] + 1, hi = n;
            for (int j = 0; j < 20; j++) {
                int mid = (lo + hi) / 2;
                if (mid - sto.query(0, mid + 1) >= y[i]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            pos[i] = lo;
            sto.upd(pos[i], 1);
        }
        set<int> in;
        int off = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (!in.count(pos[i] + 1)) {
                ++off;
            } 
            in.insert(pos[i]);
        }
        for (int i = 0; i < m; i++) {
            sto.upd(pos[i], -1);
        }
        long long ans = ch(2 * n - 1 - off, n);
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
}