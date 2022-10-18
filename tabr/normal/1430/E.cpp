#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct fenwick {
    vector<T> node;
    int n;

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> b(26);
    for (int i = n - 1; i >= 0; i--) {
        b[s[i] - 'a'].emplace_back(n - 1 - i);
    }
    vector<int> a(n);
    for (int i = n - 1; i >= 0; i--) {
        a[i] = b[s[i] - 'a'].back();
        b[s[i] - 'a'].pop_back();
    }
    debug(a);
    fenwick<long long> ft(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ft.get(a[i], n);
        ft.add(a[i], 1);
    }
    cout << ans << '\n';
    return 0;
}