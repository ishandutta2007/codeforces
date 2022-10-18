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
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[p[i]] = i;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(1 << k, (long long) 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << k); mask++) {
            if (mask & 1) {
                continue;
            }
            for (int j = 0; j < min(k, n - i); j++) {
                if (mask & (1 << j)) {
                    continue;
                }
                if (dp[i][mask] > (long long) 1e17) {
                    continue;
                }
                long long t = dp[i][mask];
                for (int l = min(n - 1, i + j + k); l >= max(0, i + j - k); l--) {
                    if (a[l] > a[i + j] && (l < i || mask & (1 << (l - i)))) {
                        t++;
                    }
                }
                int ni = i;
                int nmask = mask | (1 << j);
                while (nmask & 1) {
                    nmask >>= 1;
                    ni++;
                }
                dp[ni][nmask] = min(dp[ni][nmask], t);
            }
        }
    }
    long long ans = dp[n][0];
    fenwick<int> f(n);
    for (int i = 0; i + k + 1 < n; i++) {
        f.add(a[i], 1);
        ans += f.get(a[i + k + 1], n - 1);
    }
    cout << ans << '\n';
    return 0;
}