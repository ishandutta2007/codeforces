#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    vector<vector<int>> q(24, vector<int>(4));
    iota(q[0].begin(), q[0].end(), 0);
    for (int i = 1; i < 24; i++) {
        q[i] = q[i - 1];
        next_permutation(q[i].begin(), q[i].end());
    }
    while (tt--) {
        vector<vector<long long>> p(2, vector<long long>(4));
        for (int i = 0; i < 4; i++) {
            cin >> p[0][i] >> p[1][i];
        }
        long long ans = 1e18;
        for (int it = 0; it < 24; it++) {
            vector<vector<long long>> x(2, vector<long long>(4));
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    x[i][j] = p[i][q[it][j]];
                }
            }
            swap(x[1][1], x[1][2]);
            auto get = [&](long long k) {
                long long res = 0;
                for (int i = 0; i < 2; i++) {
                    long long cur = 1e18;
                    for (int l = 0; l < 4; l++) {
                        long long lft = x[i][l], rgt = x[i][l] + k;
                        cur = min(cur, abs(x[i][0] - lft) + abs(x[i][1] - lft) + abs(x[i][2] - rgt) + abs(x[i][3] - rgt));
                        lft = x[i][l] - k, rgt = x[i][l];
                        cur = min(cur, abs(x[i][0] - lft) + abs(x[i][1] - lft) + abs(x[i][2] - rgt) + abs(x[i][3] - rgt));
                    }
                    res += cur;
                }
                ans = min(ans, res);
                return res;
            };
            long long lo = 0, hi = 1e9;
            while (hi - lo > 2) {
                long long b = get(lo + (hi - lo) / 3);
                long long c = get(lo + (hi - lo) / 3 * 2);
                if (b < c) {
                    hi = lo + (hi - lo) / 3 * 2;
                } else {
                    lo = lo + (hi - lo) / 3;
                }
            }
            get(lo);
            get(lo + 1);
            get(lo + 2);
        }
        cout << ans << '\n';
    }
    return 0;
}