#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct sparse {
    int n, h;
    vector<vector<T>> table;
    function<T(T, T)> func;

    sparse(vector<T> v, function<T(T, T)> _func) : func(_func) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) {  // [from, to]
        int k = 32 - __builtin_clz(to - from + 1) - 1;
        return func(table[k][from], table[k][to - (1 << k) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        c[i] = b[i] - a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + c[i];
    }
    debug(pref);
    sparse<long long> smin(pref, [&](long long i, long long j) { return min(i, j); });
    sparse<long long> smax(pref, [&](long long i, long long j) { return max(i, j); });
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (pref[l] != pref[r + 1]) {
            cout << -1 << '\n';
            continue;
        }
        cout << smax.get(l + 1, r + 1) - smin.get(l + 1, r + 1) << '\n';
    }
    return 0;
}