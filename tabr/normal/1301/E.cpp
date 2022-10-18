#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct sparse2d {
    int n, m, ln, lm;
    vector<vector<vector<vector<T>>>> table;
    function<T(T, T)> func = [&](T a, T b) { return max(a, b); };
    T def = 1e9;

    sparse2d(vector<vector<T>> a) {
        n = a.size();
        m = a[0].size();
        ln = 32 - __builtin_clz(n);
        lm = 32 - __builtin_clz(m);
        table = vector<vector<vector<vector<T>>>>(ln, vector<vector<vector<T>>>(n + 1, vector<vector<T>>(lm, vector<T>(m + 1, def))));
        for (int ir = 0; ir < n; ir++) {
            for (int ic = 0; ic < m; ic++) {
                table[0][ir][0][ic] = a[ir][ic];
            }
            for (int jc = 1; jc < lm; jc++) {
                for (int ic = 0; ic <= m - (1 << (jc - 1)); ic++) {
                    table[0][ir][jc][ic] = func(table[0][ir][jc - 1][ic], table[0][ir][jc - 1][ic + (1 << (jc - 1))]);
                }
            }
        }
        for (int jr = 1; jr < ln; jr++) {
            for (int ir = 0; ir <= n - (1 << (jr - 1)); ir++) {
                for (int jc = 0; jc < lm; jc++) {
                    for (int ic = 0; ic < m; ic++) {
                        table[jr][ir][jc][ic] = func(table[jr - 1][ir][jc][ic], table[jr - 1][ir + (1 << (jr - 1))][jc][ic]);
                    }
                }
            }
        }
    }

    T get(int fromr, int tor, int fromc, int toc) const {  // [from, to]
        int kr = 32 - __builtin_clz(tor - fromr + 1) - 1;
        int kc = 32 - __builtin_clz(toc - fromc + 1) - 1;
        T t1 = func(table[kr][fromr][kc][fromc], table[kr][fromr][kc][toc - (1 << kc) + 1]);
        T t2 = func(table[kr][tor - (1 << kr) + 1][kc][fromc], table[kr][tor - (1 << kr) + 1][kc][toc - (1 << kc) + 1]);
        return func(t1, t2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> sb(n);
    vector<vector<vector<int>>> cnt(4, vector<vector<int>>(n + 1, vector<int>(m + 1)));
    vector<vector<int>> t(n, vector<int>(m));
    // R:0, G:1, Y:2, B:3
    for (int i = 0; i < n; i++) {
        cin >> sb[i];
        for (int j = 0; j < m; j++) {
            int k = 0;
            if (sb[i][j] == 'G') k = 1;
            if (sb[i][j] == 'Y') k = 2;
            if (sb[i][j] == 'B') k = 3;
            cnt[k][i + 1][j + 1]++;
            for (k = 0; k < 4; k++) {
                cnt[k][i + 1][j + 1] += cnt[k][i][j + 1] + cnt[k][i + 1][j] - cnt[k][i][j];
            }
        }
    }
    auto get = [&](int i, int j, int k, int d) {
        i++, j++;
        if (i - d < 0 || n < i || j - d < 0 || m < j) return 0;
        return cnt[k][i][j] - cnt[k][i - d][j] - cnt[k][i][j - d] + cnt[k][i - d][j - d];
    };
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (sb[i][j] == 'R' && sb[i][j + 1] == 'G' && sb[i + 1][j] == 'Y' && sb[i + 1][j + 1] == 'B') {
                int d;
                for (d = 2;; d++) {
                    int s = d * d;
                    if (get(i, j, 0, d) == s && get(i, j + d, 1, d) == s && get(i + d, j, 2, d) == s && get(i + d, j + d, 3, d) == s) {
                        continue;
                    }
                    break;
                }
                d--;
                d *= d;
                t[i][j] = d;
            }
        }
    }
    sparse2d<int> st(t);
    while (q--) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, r2--, c1--, c2--;
        int lo = 0, hi = 300;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            int a = r1 + mid - 1, b = r2 - mid, c = c1 + mid - 1, d = c2 - mid;
            if (a > b || c > d) {
                hi = mid;
                continue;
            }
            if (st.get(a, b, c, d) >= mid * mid) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo * lo * 4 << '\n';
    }
    return 0;
}