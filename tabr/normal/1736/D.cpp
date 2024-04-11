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
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> at(2);
        for (int i = 0; i < 2 * n; i++) {
            at[s[i] - '0'].emplace_back(i);
        }
        if (at[0].size() % 2 != 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> z;
        for (int i = 0; i < n; i++) {
            if (s[2 * i] != s[2 * i + 1]) {
                if (z.size() % 2 == s[2 * i] - '0') {
                    z.emplace_back(2 * i);
                } else {
                    z.emplace_back(2 * i + 1);
                }
            }
        }
        string t = s;
        for (int i = 0; i < (int) z.size(); i++) {
            t[z[i]] = s[z[(i + 1) % z.size()]];
        }
        swap(s, t);
        debug(s);
        cout << z.size();
        for (int i : z) {
            cout << " " << i + 1;
        }
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << 2 * i + 1 << " \n"[i == n - 1];
        }
    }
    return 0;
}