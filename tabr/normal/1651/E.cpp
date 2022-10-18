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
    int n;
    cin >> n;
    vector<vector<int>> g(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    long long ans = 0;
    vector<int> was(n);
    for (int r = 0; r < n; r++) {
        if (was[r]) {
            continue;
        }
        vector<int> a(1, r);
        {
            int v = g[r][0];
            while (v != r) {
                int p = a.back();
                a.emplace_back(v);
                v = p ^ g[v][0] ^ g[v][1];
            }
        }
        for (int v : a) {
            if (v < n) {
                was[v] = 1;
            }
        }
        int m = (int) a.size();
        a.insert(a.end(), a.begin(), a.end());
        for (int i = 0; i < m; i++) {
            int mn0 = n;
            int mx0 = -1;
            int mn1 = 2 * n;
            int mx1 = n - 1;
            for (int j = i; j < i + m; j++) {
                if (a[j] < n) {
                    mn0 = min(mn0, a[j]);
                    mx0 = max(mx0, a[j]);
                } else {
                    mn1 = min(mn1, a[j]);
                    mx1 = max(mx1, a[j]);
                }
                if (j == i + m - 1) {
                    if (i == 0) {
                        ans += 1LL * m / 2 * (mn0 + 1) * (n - mx0) * (mn1 - n + 1) * (2 * n - mx1);
                    }
                    break;
                }
                if (j - i + 1 < 2) {
                    continue;
                }
                int x = a[i + m - 1];
                int y = a[j + 1];
                if (mn0 <= x && x <= mx0) {
                    continue;
                }
                if (mn1 <= x && x <= mx1) {
                    continue;
                }
                if (mn0 <= y && y <= mx0) {
                    continue;
                }
                if (mn1 <= y && y <= mx1) {
                    continue;
                }
                int l0 = -1;
                int r0 = n;
                int l1 = n - 1;
                int r1 = 2 * n;
                if (x < mn0) {
                    l0 = max(l0, x);
                } else if (x < n) {
                    r0 = min(r0, x);
                } else if (x < mn1) {
                    l1 = max(l1, x);
                } else {
                    r1 = min(r1, x);
                }
                if (y < mn0) {
                    l0 = max(l0, y);
                } else if (y < n) {
                    r0 = min(r0, y);
                } else if (y < mn1) {
                    l1 = max(l1, y);
                } else {
                    r1 = min(r1, y);
                }
                int mm = (j - i + 1) / 2;
                ans += 1LL * mm * (mn0 - l0) * (r0 - mx0) * (mn1 - l1) * (r1 - mx1);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}