#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct fenwick {
    int n;
    vector<T> node;

    fenwick(int _n) : n(_n) {
        node.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {  // [0, x]
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    T get(int x, int y) {  // [x, y]
        return (get(y) - (x ? get(x - 1) : 0));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int m = (int) 6e5 + 10;
    int n;
    cin >> n;
    fenwick<long long> sum(m);
    fenwick<int> cnt(m);
    vector<int> a(n);
    vector<int> c(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long ps = 0;
        int pc = 0;
        for (int j = a[i] - 1; j < m; j += a[i]) {
            long long cs = sum.get(j);
            int cc = cnt.get(j);
            ans += (cs - ps) - 1LL * (j + 1 - a[i]) * (cc - pc);
            pc = cc;
            ps = cs;
        }
        ans += 1LL * a[i] * cnt.get(m - 1);
        int b = (int) round(sqrt(a[i] + 1));
        for (int j = 1; a[i] / j > b; j++) {
            if (c[j]) {
                ans -= a[i] / j * j;
            }
        }
        for (int j = b; j >= 1; j--) {
            int lo = a[i] / (j + 1) + 1;
            int hi = a[i] / j;
            if (lo <= hi) {
                ans -= sum.get(lo, hi) * j;
            }
        }
        c[a[i]] = 1;
        sum.add(a[i], a[i]);
        cnt.add(a[i], 1);
        cout << ans << " ";
    }
    cout << '\n';
    return 0;
}