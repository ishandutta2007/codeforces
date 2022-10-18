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
        int ans = n;
        for (char c = 'a'; c <= 'z'; c++) {
            string t;
            for (int i = 0; i < n; i++) {
                if (s[i] != c) {
                    t += s[i];
                }
            }
            if (t != string(t.rbegin(), t.rend())) {
                continue;
            }
            vector<int> a;
            int b = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != c) {
                    a.emplace_back(b);
                    b = 0;
                } else {
                    b++;
                }
            }
            a.emplace_back(b);
            int x = 0;
            for (int i = 0; i < (int) a.size() - 1 - i; i++) {
                x += abs(a[i] - a[a.size() - 1 - i]);
            }
            ans = min(ans, x);
        }
        if (ans == n) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}