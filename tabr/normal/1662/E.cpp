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

    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> at(n);
        for (int i = 0; i < n; i++) {
            at[a[i]] = i;
        }
        fenwick<int> f(2 * n);
        for (int i = 1; i < n; i++) {
            f.add(at[i], 1);
            f.add(at[i] + n, 1);
        }
        long long ans = 0;
        int last = at[0];
        for (int i = 1; i < n - 1; i++) {
            int now = at[i];
            if (last > now) {
                now += n;
            }
            f.add(at[i], -1);
            f.add(at[i] + n, -1);
            ans += 1LL * f.get(last, now) * i;
            last = at[i];
        }
        cout << ans << '\n';
    }
    return 0;
}