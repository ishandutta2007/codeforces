#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxv = 1e6 + 10, mod = 1e9 + 7;
int a[maxn];

int _add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int _sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int _mul(int a, int b) { return (long long)a * (long long)b % mod; }

struct fenwick {
    int arr[maxv];
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (int i = x; i < maxv; i += lowbit(i)) arr[i] = _add(arr[i], v);
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret = _add(ret, arr[i]);
        return ret;
    }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    bit.init();
    for (int i = 1; i <= n; ++i) {
        int t = bit.qry(a[i]);
        // cout << "a[i] = " << a[i] << " t = " << t << endl;
        int aft = _add(a[i], _mul(t, a[i]));
        // cout << "after = " << aft << endl;
        bit.add(a[i], _sub(aft, _sub(bit.qry(a[i]), bit.qry(a[i] - 1))));
    }
    cout << bit.qry(maxv - 1) << endl;
    return 0;
}