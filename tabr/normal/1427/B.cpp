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
        int k;
        cin >> k;
        string s;
        cin >> s;
        int ans = 0;
        int cur = 0;
        vector<int> c;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (cur) {
                    c.emplace_back(cur);
                    cur = 0;
                }
                ans++;
                if (i && s[i - 1] == 'W') {
                    ans++;
                }
            } else {
                cur++;
            }
        }
        int a = 0, b = cur;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                a++;
            } else {
                break;
            }
        }
        if (a && !c.empty()) {
            c.erase(c.begin());
        }
        if (a == n) {
            cout << max(0, 2 * k - 1) << '\n';
            continue;
        }
        sort(c.rbegin(), c.rend());
        a += b;
        for (int i = 0; i < k; i++) {
            if (c.empty()) {
                if (a == 0) {
                    break;
                }
                a--;
                ans += 2;
            } else {
                c.back()--;
                ans += 2;
                if (c.back() == 0) {
                    ans++;
                    c.pop_back();
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}