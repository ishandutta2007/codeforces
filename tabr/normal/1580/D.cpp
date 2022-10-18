#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    using T = pair<int, int>;
    int n, h;
    vector<vector<T>> table;
    T func(T x, T y) {
        return min(x, y);
    }

    sparse(const vector<T> &v) {
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sparse sp(b);
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, (long long) -1e18));
    dp[n][0] = 0;
    function<int(int, int)> f = [&](int l, int r) {
        if (l > r) {
            return n;
        }
        auto [x, p] = sp.get(l, r);
        int pl = f(l, p - 1);
        int pr = f(p + 1, r);
        for (int i = 0; i <= min(m, p - l); i++) {
            for (int j = 0; j <= min(m, r - p) && i + j <= min(m, r - l); j++) {
                long long t = dp[pl][i] + dp[pr][j];
                t -= 2LL * x * i * j;
                dp[p][i + j] = max(dp[p][i + j], t);
            }
        }
        for (int i = 0; i <= min(m - 1, p - l); i++) {
            for (int j = 0; j <= min(m - 1, r - p) && i + j <= min(m - 1, r - l); j++) {
                long long t = dp[pl][i] + dp[pr][j];
                t += 1LL * x * (m - 1);
                t -= 2LL * x * ((i + 1) * (j + 1) - 1);
                dp[p][i + j + 1] = max(dp[p][i + j + 1], t);
            }
        }
        return p;
    };
    cout << dp[f(0, n - 1)][m] << '\n';
    return 0;
}