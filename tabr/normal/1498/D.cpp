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
    int n, m;
    cin >> n >> m;
    vector<int> t(n), y(n);
    vector<long long> x(n);
    vector<int> ans(m + 1, -1);
    ans[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        vector<int> to(m + 1, -1);
        if (t[i] == 1) {
            x[i] = (x[i] + 99999) / 100000;
            for (int j = 0; j <= m; j++) {
                to[j] = (int)(j + x[i]);
                if (to[j] > m) {
                    to[j] = -1;
                    break;
                }
            }
        } else {
            for (int j = 0; j <= m; j++) {
                if ((j * x[i] + 99999) / 100000 > m) {
                    break;
                }
                to[j] = (int)((j * x[i] + 99999) / 100000);
            }
        }
        vector<int> a(m + 1, -1);
        for (int j = 0; j <= m; j++) {
            if (ans[j] != -1) {
                a[j] = 0;
            }
            if (a[j] == -1) {
                continue;
            }
            if (ans[j] == -1) {
                ans[j] = i + 1;
            }
            if (to[j] != -1 && a[j] != y[i]) {
                if (a[to[j]] == -1) {
                    a[to[j]] = a[j] + 1;
                }
                a[to[j]] = min(a[to[j]], a[j] + 1);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}