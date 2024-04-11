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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    int ans = 0;
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        vector<int> c(n + 1);
        auto add = [&](int x, int y) {
            if (0 <= x && x < n) {
                c[x] += y;
            }
        };
        for (int z = 0; z < m; z++) {
            if (r[z] <= i + k - 1) {
                sum += max(0, r[z] - max(i, l[z]) + 1);
            } else if (l[z] <= i) {
                sum += k;
            } else if (l[z] <= i + k - 1) {
                int t = i + k - 1 - l[z] + 1;
                sum += t;
                // int nk = l[z] - i;
                // int nl = i + k;
                // add(nl - nk + 1, 1);
                // add(r[z] - nk + 2, -1);
                // add(nl + 1, -1);
                // add(r[z] + 2, 1);
                add(i + 1, 1);
                add(r[z] - k + 2, -1);
                add(l[z] + 1, -1);
                add(r[z] - t + 2, 1);
            } else {
                add(l[z] - k + 1, 1);
                add(r[z] - k + 2, -1);
                add(l[z] + 1, -1);
                add(r[z] + 2, 1);
            }
        }
        ans = max(ans, sum);
        debug(i, sum);
        for (int j = i + 1; j < n - k; j++) {
            c[j + 1] += c[j];
        }
        for (int j = i + 1; j <= n - k; j++) {
            debug(i, j, sum + c[j]);
            c[j + 1] += c[j];
            ans = max(ans, sum + c[j]);
        }
    }
    cout << ans << '\n';
    return 0;
}