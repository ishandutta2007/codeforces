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
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                c++;
            }
        }
        if (c <= 1) {
            cout << 0 << '\n';
            continue;
        }
        c /= 2;
        int d = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                d++;
            }
            if (c + 1 == d) {
                int k = i - 1;
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j] == '*') {
                        ans += k - j;
                        k--;
                    }
                }
                k = i + 1;
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == '*') {
                        ans += j - k;
                        k++;
                    }
                }
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}