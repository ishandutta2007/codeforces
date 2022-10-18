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
        vector<int> a(n);
        for (int i = 0; i < 2; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1') {
                    a[j]++;
                }
            }
        }
        int ans = 0;
        int add = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (add == 2) {
                    ans++;
                }
                ans += 2;
                add = 1;
            } else if (a[i] == 0) {
                if (add == 3) {
                    ans += 2;
                    add = 1;
                } else if (add == 2) {
                    ans++;
                } else {
                    add = 2;
                }
            } else {
                if (add == 2) {
                    add = 1;
                    ans += 2;
                } else {
                    add = 3;
                }
            }
        }
        if (add == 2) {
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}