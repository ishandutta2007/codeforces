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
        vector<int> b, c;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (i % 2 == 0) {
                b.emplace_back(a);
            } else {
                c.emplace_back(a);
            }
        }
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a[i] = b[i / 2];
            } else {
                a[i] = c[i / 2];
            }
        }
        vector<int> d = a;
        sort(d.begin(), d.end());
        if (a == d) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}