#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

array<int, 6> a[100000];
array<int, 5> b[100000 << 5];
int e[100000][1 << 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= 0; j--) {
            cin >> a[i][j];
        }
    }
    sort(a, a + n);
    for (int i = 0, j = 0; i < n; i++) {
        reverse(a[i].begin(), a[i].begin() + m + 1);
        sort(a[i].begin(), a[i].begin() + m);
        for (int mask = 0; mask < (1 << m); mask++) {
            int l = 0;
            fill(b[j].begin(), b[j].end(), -1);
            for (int bit = 0; bit < m; bit++) {
                if (mask & (1 << bit)) {
                    b[j][l++] = a[i][bit];
                }
            }
            j++;
        }
    }
    sort(b, b + (n << m));
    int sz = (int) (unique(b, b + (n << m)) - b);
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            array<int, 5> c;
            fill(c.begin(), c.end(), -1);
            int l = 0;
            for (int bit = 0; bit < m; bit++) {
                if (mask & (1 << bit)) {
                    c[l++] = a[i][bit];
                }
            }
            e[i][mask] = (int) (lower_bound(b, b + sz, c) - b);
        }
    }
    vector<int> low(n, -1);
    vector<int> high(n, n);
    while (true) {
        bool done = true;
        vector<vector<int>> d(n);
        for (int i = 0; i < n; i++) {
            if (low[i] + 1 == high[i]) {
                continue;
            }
            done = false;
            int mid = (high[i] + low[i]) >> 1;
            d[mid].emplace_back(i);
        }
        if (done) {
            break;
        }
        vector<int> dp(sz);
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < (1 << m); mask++) {
                dp[e[i][mask]]++;
            }
            for (int id : d[i]) {
                int t = 0;
                for (int mask = 1; mask < (1 << m); mask++) {
                    if (__builtin_parity(mask)) {
                        t += dp[e[id][mask]];
                    } else {
                        t -= dp[e[id][mask]];
                    }
                }
                if (t <= i) {
                    high[id] = i;
                } else {
                    low[id] = i;
                }
            }
        }
    }
    int ans = (int) 2.1e9;
    for (int i = 0; i < n; i++) {
        if (high[i] == n) {
            continue;
        }
        ans = min(ans, a[i][m] + a[high[i]][m]);
    }
    if (ans == (int) 2.1e9) {
        ans = -1;
    }
    cout << ans << '\n';
    return 0;
}