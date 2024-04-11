#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        string t = "abacaba";
        bool ok = false;
        string ans;
        for (int i = 0; i < n - 6; i++) {
            ans = s;
            ok = true;
            for (int j = 0; j < 7; j++) {
                if (s[i + j] != '?' && s[i + j] != t[j]) {
                    ok = false;
                    break;
                }
                ans[i + j] = t[j];
            }
            if (!ok) {
                continue;
            }
            ok = true;
            for (int j = 0; j < n; j++) {
                if (ans[j] == '?') {
                    ans[j] = 'z';
                }
            }
            for (int j = 0; j < n - 6; j++) {
                if (j == i) {
                    continue;
                }
                if (t == ans.substr(j, 7)) {
                    ok = false;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            cout << "Yes" << '\n';
            cout << ans << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}