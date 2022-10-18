#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// editorial (solution without set)

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 2, vector<int>(2));
    vector<vector<int>> c(2, vector<int>(n + 2));
    vector<vector<int>> hi(2, vector<int>(n + 2));
    vector<vector<int>> lo(2, vector<int>(n + 2));
    vector<int> d(n + 2);
    for (int i = 1; i <= n; i++) {
        int k, al, bl, ar, br;
        cin >> k >> al >> bl >> ar >> br;
        if (al <= k && k <= bl) {
            c[0][i] = 1;
        }
        if (ar <= k && k <= br) {
            c[1][i] = 1;
        }
        d[i] = k;
        lo[0][i] = al;
        hi[0][i] = bl;
        lo[1][i] = ar;
        hi[1][i] = br;
    }
    hi[0][n + 1] = hi[1][n + 1] = m;
    c[0][0] = c[1][0] = c[0][n + 1] = c[1][n + 1] = dp[n + 1][0] = dp[n + 1][1] = 1;
    vector<sparse<int>> sc;
    sc.emplace_back(sparse<int>(c[0], [&](int i, int j) { return i & j; }));
    sc.emplace_back(sparse<int>(c[1], [&](int i, int j) { return i & j; }));
    vector<sparse<int>> slo;
    slo.emplace_back(sparse<int>(lo[0], [&](int i, int j) { return max(i, j); }));
    slo.emplace_back(sparse<int>(lo[1], [&](int i, int j) { return max(i, j); }));
    vector<sparse<int>> shi;
    shi.emplace_back(sparse<int>(hi[0], [&](int i, int j) { return min(i, j); }));
    shi.emplace_back(sparse<int>(hi[1], [&](int i, int j) { return min(i, j); }));
    vector<int> nxt(2, n + 1);
    for (int i = n; i >= 0; i--) {
        vector<int> nnxt = nxt;
        for (int j = 0; j < 2; j++) {
            int l = nxt[j];
            if (sc[j ^ 1].get(i + 1, l) && slo[j].get(i, l) <= d[i] && d[i] <= shi[j].get(i, l)) {
                dp[i][j] = 1;
                nnxt[j ^ 1] = i;
            }
        }
        swap(nxt, nnxt);
    }
    debug(dp);
    if (dp[0][0] + dp[0][1] == 0) {
        cout << "No" << '\n';
        return 0;
    }
    int k = 0;
    if (dp[0][1] == 0) {
        k = 1;
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << k << " ";
        if (dp[i][k] == 1) {
            k ^= 1;
        }
    }
    cout << '\n';
    return 0;
}