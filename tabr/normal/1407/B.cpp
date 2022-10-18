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
        sort(a.begin(), a.end());
        vector<int> b(n), c(n);
        c[0] = b[0] = a[n - 1];
        a.pop_back();
        for (int i = 1; i < n; i++) {
            int mx = -1, g = 0;
            for (int j : a) {
                if (__gcd(j, c[i - 1]) > mx) {
                    mx = __gcd(j, c[i - 1]);
                    g = j;
                }
            }
            b[i] = g;
            c[i] = __gcd(g, c[i - 1]);
            for (int j = 0; j < n - i; j++) {
                if (a[j] == g) {
                    a.erase(a.begin() + j);
                    break;
                }
            }
        }
        for (int i : b) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}