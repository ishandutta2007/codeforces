#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// (x, y, z) : x <= i <= y & n / i = z
template <typename T>
vector<tuple<T, T, T>> quotient(T n) {
    vector<tuple<T, T, T>> res;
    for (T i = 1; i * i <= n; i++) {
        res.emplace_back(i, i, n / i);
    }
    for (T i = get<2>(res.back()) - 1; i >= 1; i--) {
        T low = n / (i + 1) + 1;
        T high = n / i;
        if (low <= high) {
            res.emplace_back(low, high, i);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = (int) 1e9;
        if (a.back() < k) {
            ans = 0;
        }
        const int m = 100010;
        vector<int> b(m, (int) 1e9);
        for (int x : a) {
            auto t = quotient(x);
            b[m - 2] = b[m - 1] = min(b[m - 1], x);
            for (auto [low, high, z] : t) {
                b[high - 1] = min(b[high - 1], low - 1);
            }
        }
        for (int i = m - 2; i >= max(1, a.back() / k); i--) {
            b[i] = min(b[i], b[i + 1]);
            ans = min(ans, i - b[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}