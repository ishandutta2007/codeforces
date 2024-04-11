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
        int n, m;
        cin >> n >> m;
        vector<int> k(m);
        vector<vector<int>> f(m);
        vector<int> a(n);
        for (int i = 0; i < m; i++) {
            cin >> k[i];
            f[i].resize(k[i]);
            for (int j = 0; j < k[i]; j++) {
                cin >> f[i][j];
                f[i][j]--;
                a[f[i][j]]++;
            }
        }
        int mp = (int)(max_element(a.begin(), a.end()) - a.begin());
        vector<int> ans(m, mp);
        int cnt = 0;
        int t = m / 2;
        for (int i = 0; i < m; i++) {
            for (int j : f[i]) {
                if (mp != j) {
                    ans[i] = j;
                    cnt++;
                    break;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (cnt == t) {
                break;
            }
            if (ans[i] == mp) {
                continue;
            }
            for (int j : f[i]) {
                if (mp == j) {
                    ans[i] = j;
                    cnt--;
                    break;
                }
            }
        }
        debug(cnt, t);
        if (cnt == t || a[mp] <= (m + 1) / 2) {
            cout << "YES" << '\n';
            for (int i : ans) {
                cout << i + 1 << " ";
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}