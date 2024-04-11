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
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        if (m % 2 == 1) {
            cout << "YES" << '\n';
            for (int i = 0; i <= m; i++) {
                cout << i % 2 + 1 << " ";
            }
            cout << '\n';
            continue;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i][j] == s[j][i]) {
                    for (int k = 0; k <= m; k++) {
                        ans.emplace_back(k % 2 == 0 ? i + 1 : j + 1);
                    }
                    break;
                }
            }
            if (!ans.empty()) {
                break;
            }
        }
        if (!ans.empty()) {
            cout << "YES" << '\n';
            for (int i : ans) {
                cout << i << " ";
            }
            cout << '\n';
            continue;
        }
        if (n == 2) {
            cout << "NO" << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            int a = -1, b = -1;
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'a') {
                    a = j;
                } else if (s[i][j] == 'b') {
                    b = j;
                }
            }
            if (min(a, b) >= 0) {
                cout << "YES" << '\n';
                vector<int> p = {i, a, i, b};
                int k = 1;
                if (m % 4 == 0) {
                    k = 0;
                }
                for (int j = 0; j <= m; j++) {
                    cout << p[k] + 1 << " ";
                    k = (k + 1) % 4;
                }
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}