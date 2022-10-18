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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (s == string(n, '0')) {
            cout << 0 << '\n';
            continue;
        }
        int x = (int) (find(s.begin(), s.end(), '1') - s.begin());
        int y = (int) (s.rend() - find(s.rbegin(), s.rend(), '1') - 1);
        if (x != y) {
            if (n - 1 - y <= k) {
                k -= n - 1 - y;
                swap(s[y], s[n - 1]);
            }
            if (x <= k) {
                k -= x;
                swap(s[x], s[0]);
            }
        } else {
            if (n - 1 - y <= k) {
                k -= n - 1 - y;
                swap(s[y], s[n - 1]);
            } else if (x <= k) {
                k -= x;
                swap(s[x], s[0]);
            }
        }
        int ans = 0;
        if (s[0] == '1') {
            ans += 10;
        }
        if (s[n - 1] == '1') {
            ans += 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '1') {
                ans += 11;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}