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
    string s;
    cin >> s;
    int n = (int)s.size();
    s.push_back('\0');
    vector<string> ans(n + 1);
    vector<int> a(n + 1);
    vector<char> b(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != s[i + 1]) {
            a[i] = a[i + 1] + 1;
            ans[i] = s[i] + ans[i + 1];
            if (a[i] >= 11) {
                ans[i] = ans[i].substr(0, 5) + "..." + ans[i].substr(9, 2);
            }
            if (!ans[i + 1].empty()) {
                if (s[i] == ans[i + 1][0]) {
                    b[i] = b[i + 1];
                } else {
                    b[i] = ans[i + 1][0];
                }
            }
        } else {
            string x = string(2, s[i]);
            string y = ans[i + 2].substr(0, min(2, a[i + 2]));
            if (x > y || (x == y && b[i + 2] <= s[i])) {
                a[i] = a[i + 2];
                ans[i] = ans[i + 2];
                b[i] = b[i + 2];
            } else {
                a[i] = a[i + 2] + 2;
                if (a[i] >= 11) {
                    ans[i] = string(2, s[i]) + ans[i + 2].substr(0, 3) + "..." + ans[i + 2].substr((int)ans[i + 2].size() - 2, 2);
                } else {
                    ans[i] = string(2, s[i]) + ans[i + 2];
                }
                b[i] = b[i + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << ans[i] << '\n';
    }
    return 0;
}