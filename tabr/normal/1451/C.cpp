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
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        vector<int> a(25);
        string ans = "Yes";
        for (int i = 0; i < n; i++) {
            if (s[i] > t[i]) {
                ans = "No";
            } else {
                for (int j = s[i] - 'a'; j < t[i] - 'a'; j++) {
                    a[j]++;
                }
            }
        }
        for (int i = 0; i < 25; i++) {
            if (a[i] % k) {
                ans = "No";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}