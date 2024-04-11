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
        long long ans = 0;
        vector<long long> t;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                ans += i;
                t.emplace_back((n - 1 - i) - i);
            } else {
                ans += n - 1 - i;
                t.emplace_back(i - (n - 1 - i));
            }
        }
        sort(t.rbegin(), t.rend());
        for (int i = 0; i < n; i++) {
            ans += max(0LL, t[i]);
            cout << ans << " \n"[i == n - 1];
        }
    }
    return 0;
}