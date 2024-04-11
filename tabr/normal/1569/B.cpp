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
        int n;
        string s;
        cin >> n >> s;
        vector<string> ans(n, string(n, '='));
        vector<int> c;
        for (int i = 0; i < n; i++) {
            if (s[i] == '2') {
                c.emplace_back(i);
            }
        }
        int m = (int) c.size();
        if (m == 1 || m == 2) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            ans[i][i] = 'X';
        }
        for (int i = 0; i < m; i++) {
            ans[c[i]][c[(i + 1) % m]] = '+';
            ans[c[(i + 1) % m]][c[i]] = '-';
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}