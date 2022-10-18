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
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            string s;
            cin >> s;
            for (int j = 0; j < k; j++) {
                if (s[j] == 'D') {
                    a[i]++;
                } else {
                    a[i]--;
                }
            }
            a[i] %= 10;
            a[i] += 10;
            a[i] %= 10;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}