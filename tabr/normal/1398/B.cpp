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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> a(1, 1);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                a.emplace_back(0);
            }
            a.back()++;
        }
        if (s[0] == '0') {
            a.erase(a.begin());
        }
        vector<int> b;
        for (int i = 0; i < a.size(); i += 2) {
            b.emplace_back(a[i]);
        }
        sort(b.rbegin(), b.rend());
        int ans = 0;
        for (int i = 0; i < b.size(); i += 2) {
            ans += b[i];
        }
        cout << ans << '\n';
    }
    return 0;
}