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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        vector<int> b, r;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                b.emplace_back(a[i]);
            } else {
                r.emplace_back(a[i]);
            }
        }
        sort(b.begin(), b.end());
        sort(r.rbegin(), r.rend());
        string ans = "YES";
        for (int i = 0; i < (int) b.size(); i++) {
            if (i + 1 > b[i]) {
                ans = "NO";
            }
        }
        for (int i = 0; i < (int) r.size(); i++) {
            if (n - i < r[i]) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}