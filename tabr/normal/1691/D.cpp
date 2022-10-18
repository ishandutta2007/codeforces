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

    T get(int l, int r) {
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return func(table[k][l], table[k][r - (1 << k)]);
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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        vector<pair<long long, int>> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = make_pair(a[i], i);
        }
        sparse<pair<long long, int>> amax(b, [&](auto x, auto y) { return max(x, y); });
        sparse<long long> pmax(pref, [&](auto x, auto y) { return max(x, y); });
        sparse<long long> pmin(pref, [&](auto x, auto y) { return min(x, y); });
        string ans = "YES";
        function<void(int, int)> Solve = [&](int l, int r) {
            if (r - l <= 1) {
                return;
            }
            int m = amax.get(l, r).second;
            long long x = pmax.get(m + 1, r + 1);
            long long y = pmin.get(l, m + 1);
            if (a[m] < x - y) {
                ans = "NO";
            }
            Solve(l, m);
            Solve(m + 1, r);
        };
        Solve(0, n);
        cout << ans << '\n';
    }
    return 0;
}