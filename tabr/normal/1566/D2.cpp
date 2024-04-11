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
    while (tt--) {
        int h, w;
        cin >> h >> w;
        vector<int> a(h * w);
        for (int i = 0; i < h * w; i++) {
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for (int i = 0; i < h * w; i++) {
            a[i] = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
        }
        int m = (int) b.size();
        vector<int> c(m + 1);
        for (int i = 0; i < h * w; i++) {
            c[a[i] + 1]++;
        }
        for (int i = 0; i < m; i++) {
            c[i + 1] += c[i];
        }
        vector<int> x(m), y(m);
        vector<vector<int>> e(m);
        vector<int> id(m);
        for (int i = 0; i < m; i++) {
            for (int j = c[i]; j < c[i + 1]; j++) {
                e[i].emplace_back(j);
            }
            sort(e[i].begin(), e[i].end(), [&](int j, int k) {
                if (j / w != k / w) {
                    return j / w < k / w;
                }
                return j % w > k % w;
            });
        }
        vector<vector<int>> d(h, vector<int>(w));
        long long ans = 0;
        for (int p = 0; p < h * w; p++) {
            int q = a[p];
            int xx = e[q][id[q]] / w;
            int yy = e[q][id[q]] % w;
            for (int j = 0; j < yy; j++) {
                ans += d[xx][j];
            }
            d[xx][yy] = 1;
            id[q]++;
        }
        cout << ans << '\n';
    }
    return 0;
}