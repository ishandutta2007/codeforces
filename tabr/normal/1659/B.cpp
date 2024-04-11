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
        vector<int> a(n);
        if (k % 2 == 1) {
            for (int i = 0; i < n; i++) {
                s[i] ^= '0' ^ '1';
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && k > 0) {
                k--;
                s[i] = '1';
                a[i]++;
            }
        }
        a.back() += k;
        if (k % 2 == 1) {
            s.back() = '0';
        }
        cout << s << '\n';
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}