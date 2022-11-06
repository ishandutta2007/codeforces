#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;

struct Fenwick {
    int arr[2][maxn];
    inline int lowbit(int x) {
        return x & -x;
    }
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    void add(int x, int p, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[p][i] += v;
    }
    int qry(int x, int p) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[p][i];
        return ret;
    }
} bit;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, a, b, q; cin >> n >> k >> a >> b >> q;
    bit.init();
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int d, ai; cin >> d >> ai;
            int qb = bit.qry(d, 0) - bit.qry(d - 1, 0), qa = bit.qry(d, 1) - bit.qry(d - 1, 1);
            bit.add(d, 0, min(b - qb, ai)); bit.add(d, 1, min(a - qa, ai));
        } else {
            int p; cin >> p;
            cout << bit.qry(p - 1, 0) + bit.qry(n, 1) - bit.qry(p + k - 1, 1) << endl;
        }
    }
    return 0;
}