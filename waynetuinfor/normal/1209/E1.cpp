#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
        }
        vector<int> z(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) z[i] = max(z[i], a[j][i]);
        }
        vector<int> od(m);
        iota(od.begin(), od.end(), 0);
        sort(od.begin(), od.end(), [&](int i, int j) { return z[i] > z[j]; });
        vector<int> dp(1 << n);
        for (int i = 0; i < min(n, m); ++i) {
            deque<int> v(n);
            for (int j = 0; j < n; ++j) v[j] = a[j][od[i]];
            vector<int> nxt(1 << n);
            for (int j = 0; j < n; ++j) {
                vector<int> med(dp.begin(), dp.end());
                for (int s = 0; s < (1 << n); ++s) {
                    for (int k = 0; k < n; ++k) {
                        if ((s >> k & 1) == 0) med[s ^ (1 << k)] = max(med[s ^ (1 << k)], med[s] + v[k]);
                    }
                }
                for (int s = 0; s < (1 << n); ++s) nxt[s] = max(nxt[s], med[s]);
                v.push_back(v[0]);
                v.pop_front();
            }
            dp = nxt;
        }
        printf("%d\n", dp[(1 << n) - 1]);
    }
    return 0;
}